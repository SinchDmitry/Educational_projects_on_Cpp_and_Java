
drop table if exists chat.user, chat.chatroom, chat.message;
create table if not exists chat.user (
    id bigserial primary key unique,
    login text,
    password varchar(20)
);
