show databases;

create database mock_test;

use mock_test;

create table presidents(
pres_id int not null auto_increment,
pres_name varchar(50),
funds int,
primary key(pres_id),
index(pres_id, pres_name));

insert into presidents value (1240010, 'George Washington', 541200);

insert into presidents (pres_name, funds) values
('John Adams', 846600),
('Thomas Jefferson', 761510),
('James Madison', 1200410),
('James Monroe', 453300),
('John Q Adams', 493310),
('Andrew Jackson', 3500000),
('Martin Van Buren', 640000),
('John Tyler', 4351700),
('Zachary Taylor', 640000),
('Millard Fillmore', 893000),
('Franklin Pierce', 720000),
('James Buchanan', 350000);

select * from presidents;

create view presidentNames as
select pres_name, funds
from presidents;

alter view presidentNames as
select pres_name as President, Funds from presidents;

alter table presidents add column term varchar(20);

update presidents set term = '4 years';

alter table presidents auto_increment 54321002;

alter table presidents modify column term varchar(20) default '4 years';

insert into presidents (pres_name, funds) values
('James Polk', 842000),
('Abraham Lincoln', 431000),
('Andrew Johnson', 613400);

rename table presidentNames to funds_collected;

select * from funds_collected;

delete from presidents where funds < 500000;

drop table presidents;