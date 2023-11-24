# Project1
Автор проекта (и единственный участник): Шпренгер Алиса.

Проект представляет из себя пользовательский консольный чат.

Функционал:
- регистрация пользователей
- отправка сообщений конкретному пользователю, всем пользователям
- смена логина, имя, пароля
- чтение новых сообщений
- чтение всей переписки с конкретным пользователем

Реализовано 3 класса:
- ListUsers (список со всеми пользователями)
- User (конкретный пользователь) класс наследник базового класса Messages 
- Messages (список новых сообщений пользователя)

Использованы структуры данных:
- set (Alllogins хранит логины всех пользователей)
- map (AllMessages хранит переписки всех пользователей со всеми)

Основные функции в файле main:
- ENTER() (для регистрации пользователей или входа под конкретной учётной записью)
- send_message(User* current_user) (отправка сообшения конкретному пользователю)
- send_message_all(User* current_user) (отправка сообщения всем пользователям)
- check_messages(User* current_user) (для проверки новых сообщений и чтения всей переписки с конкретным пользователем)
- settings(current_user) (можно посмотреть имя пользователя и логин текущей учётной записи, сменить логин, имя, пароль)
- list_of_users() (можно вывести список всех пользователей(логин + имя), отсортировать его по имени, логину)


