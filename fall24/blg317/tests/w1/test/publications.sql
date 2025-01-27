create database PUBLICATIONS;
use PUBLICATIONS;

create table PUBLISHER (
	publisher_id	int,
    publisher_name 	varchar(50),
    phone			char(15),
    primary key (publisher_id)
);

create table AUTHOR (
	author_id		int,
    author_name		varchar(50),
    email			varchar(50),
    primary key (author_id)
);

create table BOOK (
	ISBN			char(20),
    publisher_id	int,
    author_id		int,
    title			varchar(50),
    primary key (ISBN, publisher_id, author_id),
    foreign key (publisher_id) references publisher (publisher_id),
    foreign key (author_id) references author (author_id)
);

create table EMPLOYEE (
	emp_id 			int,
    emp_name 		varchar(50),
    email			varchar(50),
    primary key (emp_id)
);

insert into publisher values (10, 'Addison-Wesley', '212-303-8421');
insert into publisher values (20, 'Pearson Premtice Hall', null);
insert into publisher values (30, 'McGraw-Hill', '216-404-02354');

insert into author values (100, 'Addison', 'elm@uta');
insert into author values (200, 'Ullman', 'ulm@ibm');
insert into author values (300, 'Weinberg', null);
insert into author values (400, 'Silberschatz', 'slb@ms');
insert into author values (500, 'Ramakrishnan', 'rma@wisc');
update author
set author_name = 'Elmasri'
where author_id = 100;

insert into book values ('A0012345', 10, 100, 'Fundamentals of Database');
insert into book values ('F0072261', 20, 100, 'Database Design');
insert into book values ('B0033224', 20, 200, 'Database Systems');
insert into book values ('C0092831', 30, 300, 'SQL Reference');
insert into book values ('D0027354', 30, 400, 'Database Concepts');
insert into book values ('E0091237', 30, 500, 'Database Management System');

insert into employee values (10, 'Sommer', 'smr@net');
insert into employee values (20, 'Chang', 'chng@edu');
insert into employee values (100, 'Elmasri', 'elm@uta');
insert into employee values (500, 'Ramakrishnan', 'rma@wisc');
