drop schema if exists chat cascade;
create schema if not exists chat;

drop table if exists chat.user, chat.chatroom, chat.message;
create table if not exists chat.user (
    id bigserial primary key unique,
    login text,
    password varchar(20)
);

create table if not exists chat.chatroom (
    id bigserial primary key unique,
    name varchar(80),
    host_id bigint references chat.user(id)
);

create table if not exists chat.message (
    id bigserial primary key unique,
    author_id  bigint references chat.user(id),
    room_id bigint references chat.chatroom(id),
    text text,
    time timestamp default localtimestamp(0)
);

-- create table if not exists chat.join_room (
--   host_id int references chat.user(id),
--   room_id int references chat.chatroom(id)
-- );
