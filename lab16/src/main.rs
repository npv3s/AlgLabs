mod file_work;
use file_work::Table as Table;
use std::path::Path;

/// Годовые дивидендов
static DIVIDEND_RATE: f64 = 0.64;
/// Цена акции
static STOCK_PRICE: usize = 1000;


/**
 Эта функция берёт таблицу, выкидывает из неё всех,
 у кого меньше 150 акций. Далее считаются буквы в именах,
 и в max_name пишется наибольшее значение.
 Потом выводится таблица имён
**/
fn more_than_150(table: &Table) {
    println!("Список людей, у которых больше 150 акций");
    let table: Vec<(String, String, u64)>
        = table.content.iter()
        .filter(|x| x.stocks > 150)
        .map(|x| x.to_array())
        .collect();
    let max_name = table.iter()
        .map(|x| x.0.chars().count())
        .max().unwrap();
    println!("┌{}┐", "─".repeat(max_name));
    for raw in table.iter() {
        println!("|{:width$}|", raw.0, width = max_name);
    }
    println!("└{}┘", "─".repeat(max_name));
}

/**
 Эта функция берёт таблицу, и вместо количества акций
 суёт в это место, сколько дивидендов получится за год.
 Далее по аналогии с предыдущей функций находится к-во
 символов в самом длинном имени, и самой длинной сумме.
 Дальше просто печатается таблица
**/
fn dividends(table: &Table) {
    println!("Таблица дивидендов");
    let table: Vec<(String, String, u64)>
        = table.content.iter()
        .map(|x| x.to_array())
        .map(|x| (x.0, x.1, (x.2 as f64 * STOCK_PRICE as f64 * DIVIDEND_RATE) as u64))
        .collect();
    let max_name = table.iter()
        .map(|x| x.0.chars().count())
        .max().unwrap();
    let max_money = table.iter()
        .map(|x| x.2.to_string().chars().count())
        .max().unwrap();
    println!("┌{}┬{}┐", "─".repeat(max_name), "─".repeat(max_money + 1));
    for raw in table.iter() {
        println!("|{:name_width$}|{:money_width$}₽|", raw.0, raw.2, name_width = max_name, money_width = max_money);
    }
    println!("└{}┴{}┘", "─".repeat(max_name), "─".repeat(max_money + 1));

}

fn main() {
    let mut table = Table {
        path: Path::new("C:\\Users\\npv3s\\Desktop\\tmp.csv"),
        content: Vec::new(),
    };

    table.open();
    more_than_150(&table);
    dividends(&table);

}
