drop table if exists users;
create table if not exists  users (
    id bigserial primary key unique,
    login text,
    password varchar(100)
);

create table if not exists messages (
    id bigserial primary key unique,
    author text,
    message text,
    data timestamp
);