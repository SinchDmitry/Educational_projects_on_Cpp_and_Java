drop table if exists users;
create table if not exists  users (
    id bigserial primary key unique,
    login text,
    password varchar(100)
);
