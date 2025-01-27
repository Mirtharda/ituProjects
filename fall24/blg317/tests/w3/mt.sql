create database  grammy;
use grammy;

create table performers
(name varchar(50),
genre varchar(50),
primary key (name));

create table grammy_nominations
(name varchar(50),
category varchar(50),
year 	int,
isWinner varchar(50),
primary key (name, category, year),
foreign key (name) references performers (name));

insert into performers values
		('Coldplay', 'Rock'),
        ('Amy Winehouse', 'R&B'),
        ('Arizona Shakes', 'Rock'),
        ('Frank Ocean', 'R&B'),
        ('The Black Keys', 'Rock');
	
insert into grammy_nominations values
		('Arizona Shakes', 'new artist'