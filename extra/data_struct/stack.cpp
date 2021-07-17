#include <string>
#include <iostream>

using namespace std;

struct u8_stack_item_t {
    u8_stack_item_t* next;
    u8_stack_item_t* prev;
    uint8_t data;
};
struct u8_stack_t {
    u8_stack_item_t* head;
    u8_stack_item_t* tail;
    uint8_t length;
};

uint8_t stack_pop(u8_stack_t* opStack)
{
    if(opStack->head == nullptr)
    {
        return 0;
    }else
    {
        u8_stack_item_t* node;
        node = opStack->head;
        opStack->head = node->next;
        if(opStack->length == 1)
        {
            opStack->tail = nullptr;
        }else
        {
            node->next->prev = nullptr;
        }
        node->next = nullptr;
        opStack->length--;
        return node->data;
    }
}

void stack_push(u8_stack_t* opStack, uint8_t data)
{
    auto* node = (u8_stack_item_t*) malloc(sizeof(u8_stack_item_t));
    node->next = nullptr;
    node->prev = nullptr;
    node->data = data;
    if(opStack->head == nullptr)
    {
        opStack->head = node;
        opStack->tail = node;
    }else
    {
        opStack->head->prev = node;
        node->next = opStack->head;
        opStack->head = node;
    }
    opStack->length++;
}

void stack_print(u8_stack_t* opStack)
{
    u8_stack_item_t* node;
    node = opStack->head;
    int i = 0;
    while(node != nullptr)
    {
        cout<<"位置："<<i<<"值："<<std::hex<<int(node->data)<<endl;
        node = node->next;
        i++;
    }
}

void stack_test()
{
    auto* opStack = (u8_stack_t*) malloc(sizeof(u8_stack_t));
    uint8_t data;
    opStack->head = nullptr;
    opStack->tail = nullptr;
    opStack->length = 0;
    stack_push(opStack, 0x01);
    stack_print(opStack);
    stack_push(opStack, 0x02);
    stack_print(opStack);
    stack_push(opStack, 0x03);
    stack_print(opStack);
    data = stack_pop(opStack);
    cout<<"数据："<<std::hex<<int(data)<<endl;
    stack_print(opStack);
    data = stack_pop(opStack);
    cout<<"数据："<<std::hex<<int(data)<<endl;
    stack_print(opStack);
    data = stack_pop(opStack);
    cout<<"数据："<<std::hex<<int(data)<<endl;
    stack_print(opStack);
}

int main()
{
  stack_test();
}
/*
Output:

位置：0值：1
位置：0值：2
位置：1值：1
位置：0值：3
位置：1值：2
位置：2值：1
数据：3
位置：0值：2
位置：1值：1
数据：2
位置：0值：1
数据：1
*/
