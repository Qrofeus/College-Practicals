/* Trial for cursor */

delimiter //
create procedure getPresidents()
begin

	declare p_id int;
    declare p_name varchar(50);
    declare finished int default 0;
    declare output varchar(4000) default '';
    declare c0 cursor for select id, name from presidents;
    
    declare continue handler for not found set finished = 1;
    open c0;
    
    loop_label: LOOP
		if finished = 1 then
			leave loop_label;
		end if;
		
		fetch c0 into p_id, p_name;
		set output = concat(output, concat(p_id, ' - ', p_name, char(10)));
    end LOOP loop_label;
    close c0;
    select output;
end//

delimiter ;

call getPresidents();

drop procedure getPresidents;