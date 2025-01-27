create database PRODUCTIONS;
use PRODUCTIONS;

create table CATEGORY (
	category_id		int AUTO_INCREMENT,
    category_name	varchar(50),
    primary key (category_id)
);

insert into CATEGORY values 
			(1, 'Electronics'),
            (2, 'Furniture');
				

create table PRODUCT (
	product_id		int primary key,
    product_name varchar(20),
    category_id 	int,
    foreign key (category_id) references category (category_id)
			ON DELETE RESTRICT
);

insert into PRODUCT values
			(10, 'Desk', 2),
            (20, 'Chair', 2),
            (30, 'TV', 1),
            (40, 'Refrigirator', 1);
            
insert into product values
			(50, 'Bicycle', 3);
            
delete from category 
where category_id = 1;