/*Write a database trigger on Library table.
The System should keep track of the records that are being updated or deleted.
The old value of updated or deleted records should be added in Library_Audit table.*/

use college;

create table Lib_Records(
	book_id varchar(5),
    roll_no int
);

create table Library_Audit(
	audit_message varchar(100)
);

create trigger insert_trig after insert on Lib_Records
for each row insert into Library_Audit value(concat('Book Id: ', new.book_id, ' BORROWED by student: ', new.roll_no));

create trigger remove_trig after delete on Lib_Records
for each row insert into Library_Audit value(concat('Book Id: ', old.book_id, ' RETURNED by student: ', old.roll_no));

insert into Lib_Records values
('A54E2', 21),
('HS531', 65),
('FFE3Q', 20),
('IHJQ7', 21),
('HHVI1', 38),
('LWNSA', 83),
('NWNQ8', 14),
('NIMA8', 37),
('MAHNE', 29);

delete from Lib_Records;
delete from Lib_Records where roll_no < 30;

delete from Library_Audit;

select * from Lib_Records;

select * from Library_Audit;

drop table Lib_Records;

drop table Library_Audit;

drop trigger insert_trig;

drop trigger remove_trig;

show triggers;