use std::fs::{File, write};
use std::io::prelude::*;
use std::path::Path;
use std::mem;

#[derive(Clone)]
pub struct Person {
    pub name: [String; 3],
    tlf: String,
    pub stocks: u64,
}

impl Person {
    pub fn to_array(&self) -> (String, String, u64) {
        (self.name.iter()
             .map(|x| x.clone())
             .collect::<Vec<String>>()
             .join(" "),
         self.tlf.clone(), self.stocks)
    }
    fn to_csv(&self) -> String {
        format!("{},{},{},{},{}",
                self.name[0], self.name[1], self.name[2],
                self.tlf, self.stocks)
    }
}

pub struct Table<'a> {
    pub path: &'a Path,
    pub content: Vec<Person>,
}

impl Table<'_> {
    fn content_to_str(&self) -> String {
        self.content.iter().map(|x| x.clone().to_csv()).collect::<Vec<String>>().join("\n")
    }
    pub fn create(&self) {
        write(self.path, self.content_to_str()).expect("Не удалось записать файл!");
    }
    pub fn open(&mut self) {
        self.content.clear();
        let display = self.path.display();

        let mut file = match File::open(self.path) {
            Err(why) => panic!("Не получилось открыть {}: {}", display, why),
            Ok(file) => file,
        };

        let mut s = String::new();
        file.read_to_string(&mut s)
            .expect(format!("Не получилось прочитать {}", display).as_ref());

        for item in s.split('\n') {
            let raw: Vec<&str> = item.split(',').collect();
            if raw.is_empty() { continue; }
            if raw.len() != 5 { panic!("Ряд таблицы содержит не 5 элементов!\n{}", item) }
            let name = [raw[0].to_string(), raw[1].to_string(), raw[2].to_string()];
            let tlf = raw[3].to_string();
            let stocks: u64 = raw[4].trim().parse()
                .expect(format!("В графу \"Акции\" внесено не число: {}", raw[4]).as_ref());
            self.content.push(Person { name, tlf, stocks });
        }
    }
    pub fn delete_raw(&mut self, raw: usize) -> Result<(), &str> {
        if raw >= self.content.len() { return Err("Такого ряда не существует!"); }
        self.content.remove(raw);
        Ok(())
    }
    pub fn add_raw(&mut self, person: Person) {
        self.content.push(person)
    }
    pub fn change_raw(&mut self, raw: usize, person: Person) -> Result<(), &str> {
        if raw >= self.content.len() { return Err("Такого ряда не существует!"); }
        mem::replace(&mut self.content[raw], person);
        Ok(())
    }
}

#[cfg(test)]
#[allow(unused_must_use)]
mod tests {
    use super::*;

    fn sample_table() -> Table<'static> {
        Table {
            path: Path::new("C:\\Users\\npv3s\\Desktop\\test.csv"),
            content: vec![Person {
                name: ["Иванов".to_string(), "Иван".to_string(), "Иванович".to_string()],
                tlf: "+7(900)222-22-22".to_string(),
                stocks: 100,
            },
                          Person {
                              name: ["Петров".to_string(), "Пётр".to_string(), "Петрович".to_string()],
                              tlf: "+7(900)333-33-33".to_string(),
                              stocks: 200,
                          }],
        }
    }

    #[test]
    #[should_panic(expected = "Не получилось открыть C:\\blablablablabla\\ebfvlisefb.txt: Системе не удается найти указанный путь. (os error 3)")]
    fn nonexistent_file() {
        let mut table = Table {
            path: Path::new("C:\\blablablablabla\\ebfvlisefb.txt"),
            content: Vec::new(),
        };
        table.open();
    }

    #[test]
    fn open_test() {
        let mut table = Table {
            path: Path::new("C:\\Users\\npv3s\\Desktop\\tmp.csv"),
            content: Vec::new(),
        };

        table.open();
        assert_eq!(table.content_to_str(), sample_table().content_to_str());
    }

    #[test]
    fn delete_nonexistent_raw() {
        let mut table = sample_table();
        assert_eq!(table.delete_raw(2), Err("Такого ряда не существует!"));
    }

    #[test]
    fn delete_raw_test() {
        let mut table = sample_table();
        table.delete_raw(1);
        let predict_table = Table {
            path: Path::new("C:\\tmp.csv"),
            content: vec![Person {
                name: ["Иванов".to_string(), "Иван".to_string(), "Иванович".to_string()],
                tlf: "+7(900)222-22-22".to_string(),
                stocks: 100,
            }],
        };
        assert_eq!(table.content_to_str(), predict_table.content_to_str());
    }

    #[test]
    fn add_test() {
        let mut table = sample_table();
        table.delete_raw(1);
        table.add_raw(Person {
            name: ["Петров".to_string(), "Пётр".to_string(), "Петрович".to_string()],
            tlf: "+7(900)333-33-33".to_string(),
            stocks: 200,
        });
        assert_eq!(table.content_to_str(), sample_table().content_to_str());
    }

    #[test]
    fn change_raw_test() {
        let mut table1 = sample_table();
        let mut table2 = sample_table();
        table1.delete_raw(0);
        table2.delete_raw(1);
        let result = table2.change_raw(0, Person {
            name: ["Петров".to_string(), "Пётр".to_string(), "Петрович".to_string()],
            tlf: "+7(900)333-33-33".to_string(),
            stocks: 200,
        });
        assert_eq!(result, Ok(()));
        assert_eq!(table1.content_to_str(), table2.content_to_str());
    }

    #[test]
    fn content_to_str_test() {
        let table = sample_table();
        let predict_str = "Иванов,Иван,Иванович,+7(900)222-22-22,100\nПетров,Пётр,Петрович,+7(900)333-33-33,200";
        assert_eq!(table.content_to_str(), predict_str.to_string());
    }

    #[test]
    fn create_test() {
        let mut table = sample_table();
        table.create();
        table.open();
        assert_eq!(table.content_to_str(), sample_table().content_to_str());
    }
}