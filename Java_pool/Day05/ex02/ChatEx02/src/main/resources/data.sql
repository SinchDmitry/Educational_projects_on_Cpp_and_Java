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
        ('Oleg', 'yaoleg');

insert into chat.chatroom (name, host_id)
values  ('General', random_val()),
        ('PodvalSoZmeyami', random_val()),
        ('Announcement', random_val()),
        ('Adm', random_val()),
        ('Bocal', random_val()),
        ('boloto', 5);

insert into chat.message (author_id, room_id, text)
values  (random_val(), 1, 'Tvoy kod shlyapa'),
        (random_val(), 1, 'Sam ty shlyapa'),
        (random_val(), 2, 'Privet, ya podsyadu?'),
        (random_val(), 3, 'Segodnya mafia, zavtra tancy, poslezavtra klub pingpong'),
        (random_val(), 5, 'nujno 3 chelovekda na examen');

