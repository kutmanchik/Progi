#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
  Node* next;
  Node* prev;
  int data;
};

class Link
{
private:
  Node *head, *tail;
public:
  Link()
  {
    head = NULL;
    tail = NULL;
  }

  void add(int n);
  void display();
  void Sort();
  Link concatenate(Link const &b);
};

void Link::add(int n)
{
  Node *cur = new Node;
  cur->data = n;
  cur->next = NULL;
  cur->prev = NULL;

  if(head == NULL)
  {
    head = cur;
    tail = cur;
  }
  else
  {
    cur->prev = tail;
    tail->next = cur;
    tail = cur;
  }
}

void Link::display()
{
  Node *cur = head;
  while(cur != NULL)
  {
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
}

void Link::Sort()
{
  Node *cur = head;
  Node *last = NULL;
  while(cur != last)
  {
    if(cur->next == NULL || cur->next->next == last )
    {
      if(cur->data > cur->next->data)
      {
        swap(cur->next->data, cur->data);
      }
      if(cur == head) break;
        last = cur->next;
        cur = head;
    }
    if(cur->data > cur->next->data)
    {
      swap(cur->next->data, cur->data);
    }
    cur = cur->next;
  }
}

Link Link::concatenate(Link const &b)
{
  Link link;
  Node *cur = head;
  while(cur != NULL)
  {
    link.add(cur->data);
    cur = cur->next;
  }
  cur = b.head;
  while(cur != NULL)
  {
    link.add(cur->data);
    cur = cur->next;
  }
  return link;
}

int main()
{
  Link a,b, c;
  string str;
  int list_lenght, n;
  bool second_list = false;
  while( cin >> list_lenght)
  {
    for(int i = 0 ; i < list_lenght ; i++)
    {
      cin >> n;
      if(second_list)
      {
        b.add(n);
      }
      else
      {
        a.add(n);
      }
    }
    if(second_list == false)
    {
      second_list = true;
    }
    else
    {
      c = a.concatenate(b);
      c.Sort();
      c.display();
      second_list = false;
    }
  }
  return 0;
}
