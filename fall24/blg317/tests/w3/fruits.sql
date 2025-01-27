create database fruits;
use fruits;

create table SALES(sale_id int,

product_name varchar(15),
price NUMERIC(5, 1),
quantity int,
month varchar(10) );

insert into SALES values
(101, 'Orange', 3.0, 22, 'Jan'),
(102, 'Kiwi', 0.8, 34, 'Jan'),
(103, 'Orange', 1.5, 23, 'Feb'),
(104, 'Apple', 2.0, 38, 'Feb'),
(105, 'Cherry', 2.7, 44, 'Feb'),
(106, 'Apricot', 1.2, 78, 'Feb'),
(107, 'Orange', 3.0, 76, 'March'),
(108, 'Cherry', 4.1, 60, 'March'),
(109, 'Apple', 1.6, 48, 'March'),
(110, 'Orange', 3.0, 76, 'March') ;

select COUNT(s1.product_name)
from sales s1
join sales s2
    ON s1.product_name = s2.product_name
    AND s1.month = s2.month
    AND s1.sale_id < s2.sale_id;
