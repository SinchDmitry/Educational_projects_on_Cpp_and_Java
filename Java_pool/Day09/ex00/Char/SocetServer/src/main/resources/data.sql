set time zone 'Europe/Moscow';

create or replace function random_val() returns int as $$
declare
    rnd int := floor(random() * ((5 - 1) + 1)) + 1;
begin
    return rnd;
end;
$$ language plpgsql;

insert into chat.user (login, password)
values  ('SilenceMurder', 'qwertyui'),
        ('PowerRanger', '123456789'),
        ('SpeedyRacer', 'qWeRtYuI123456789'),
        ('KamazPomoev', 'zxcvbnm'),
        ('shreck', 'boloto'),
        ('Oleg', 'yaoleg'),
        ('Oleg1', 'yaoleg'),
        ('Oleg2', 'yaoleg'),
        ('Oleg3', 'yaoleg'),
        ('Oleg4', 'yaoleg'),
        ('Oleg5', 'yaoleg'),
        ('Oleg6', 'yaoleg'),
        ('Oleg7', 'yaoleg'),
        ('Oleg8', 'yaoleg'),
        ('Oleg9', 'yaoleg'),
        ('Oleg10', 'yaoleg'),
        ('Oleg11', 'yaoleg'),
        ('Oleg12', 'yaoleg'),
        ('Oleg13', 'yaoleg'),
        ('Oleg14', 'yaoleg'),
        ('Oleg14', 'yaoleg');