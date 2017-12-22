Напишите шаблонную функцию get_size, которая принимает значение некоторого типа, 
у которого есть либо константный метод size() возвращающий size_t, 
либо поле size типа size_t, и возвращает соответствующее значение.

Пример:

std::string s{"Hello"};
size_t s_size = get_size(s);   // 5, вызывается метод size()

struct Struct 
{ 
    size_t size = 0;  
};

Struct x{10};
size_t x_size = get_size(x);  // 10, читается поле size
