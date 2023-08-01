#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

class User
{
    std::string _name;
    std::string _login;
    std::string _pass;

public:
    User() = default;

    void setname(const std::string& name)
    {
        _name = name;
    }
    const std::string& getname() const
    {
        return _name;
    }

    void setlogin(const std::string& login)
    {
        _login = login;
    }
    const std::string& getlogin() const
    {
        return _login;
    }

    void setpass(const std::string& pass)
    {
        _pass = pass;
    }
    const std::string& getpass() const
    {
        return _pass;
    }



    friend std::fstream& operator >>(std::fstream& is, User& obj);
    friend std::ostream& operator <<(std::ostream& os, const User& obj);
};

class Message
{
    std::string _text;
    std::string _sender;
    std::string _receiver;

public:
    Message(std::string text, std::string sender, std::string receiver) :_text(text), _sender(sender), _receiver(receiver) {}
    Message() = default;

    void settext(const std::string& text)
    {
        _text = text;
    }
    const std::string& gettext() const
    {
        return _text;
    }

    void setsender(const std::string& sender)
    {
        _sender = sender;
    }
    const std::string& getsender() const
    {
        return _sender;
    }

    void setreceiver(const std::string& receiver)
    {
        _receiver = receiver;
    }
    const std::string& getreceiver() const
    {
        return _receiver;
    }


    friend std::fstream& operator >>(std::fstream& is, Message& obj);
    friend std::ostream& operator <<(std::ostream& os, const Message& obj);
};


std::fstream& operator >>(std::fstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}
std::ostream& operator <<(std::ostream& os, const User& obj)
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}

std::fstream& operator >>(std::fstream& is, Message& obj)
{
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;
    return is;
}
std::ostream& operator <<(std::ostream& os, const Message& obj)
{
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    return os;
}

int main()
{
    User u_obj;

    std::fstream user_file_load("users.txt");
    if (!user_file_load)
    {
        user_file_load = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
        std::cout << "Data empty" << std::endl;
    }
    if (!user_file_load.is_open())
    {
        std::cout << "Could not open input file!" << '\n';
        return 1;
    }
    user_file_load >> u_obj;
    std::cout << u_obj << std::endl;
    user_file_load.close();
    system("chmod 600 users.txt");

    std::fstream user_file_write("users.txt");
    if (!user_file_write)
    {
        user_file_write = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (!user_file_write.is_open())
    {
        std::cout << "Could not open input file!" << '\n';
        return 1;
    }
    u_obj.setname("user1");
    u_obj.setlogin("login1");
    u_obj.setpass("pass1");
    user_file_write << u_obj << std::endl;
    user_file_write.close();
    system("chmod 600 users.txt");

    std::fstream user_file_read("users.txt");
    if (!user_file_read)
    {
        user_file_read = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (!user_file_read.is_open())
    {
        std::cout << "Could not open input file!" << '\n';
        return 1;
    }

    u_obj.setname("user2");
    u_obj.setlogin("login2");
    u_obj.setpass("pass2");
    user_file_read >> u_obj;
    std::cout << u_obj << std::endl;
    user_file_read.close();
    system("chmod 600 users.txt");

    Message m_obj;

    std::fstream message_file_load("messages.txt");
    if (!message_file_load)
    {
        message_file_load = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
        std::cout << "Data empty" << std::endl;
    }
    if (!message_file_load.is_open())
    {
        std::cout << "Could not open input file!" << '\n';
        return 1;
    }
    message_file_load >> m_obj;
    std::cout << m_obj << std::endl;
    message_file_load.close();
    system("chmod 600 messages.txt");

    std::fstream message_file_write("messages.txt");
    if (!message_file_write)
    {
        message_file_write = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (!message_file_write.is_open())
    {
        std::cout << "Could not open input file!" << '\n';
        return 1;
    }
    m_obj.settext("hello");
    m_obj.setsender("user2");
    m_obj.setreceiver("user1");
    message_file_write << m_obj << std::endl;
    message_file_write.close();
    system("chmod 600 messages.txt");

    std::fstream message_file_read("messages.txt");
    if (!message_file_read)
    {
        message_file_read = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (!message_file_read.is_open())
    {
        std::cout << "Could not open input file!" << '\n';
        return 1;
    }
    message_file_read >> m_obj;
    std::cout << m_obj << std::endl;
    message_file_read.close();
    system("chmod 600 messages.txt");

    return 0;
}