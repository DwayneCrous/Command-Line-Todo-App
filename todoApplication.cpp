#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const int MAX_TASKS = 100;

void getFileData();
void addTask();
void deleteTask();

int main()
{
  int choice;
  while (choice != 4)
  {
    cout << "What would you like to do?\n1.) Add a task\n2.) See current tasks\n3.) Delete a task\n4.) Exit program.\n";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
      addTask();
      break;
    case 2:
      getFileData();
      break;
    case 3:
      deleteTask();
      break;
    case 4:
      cout << "Goodbye! See you next time.\n";
      return 0;
    default:
      cout << "INVALID CHOICE!\n";
      break;
    }
  }
}

void getFileData()
{
  cout << "Current tasks:\n";

  string tasks[MAX_TASKS];
  int taskCount = 0;

  ifstream MyReadFile("list.txt");

  if (!MyReadFile)
  {
    cout << "No tasks found\n\n";
    return;
  }

  while (getline(MyReadFile, tasks[taskCount]) && taskCount < MAX_TASKS)
  {
    taskCount++;
  }

  MyReadFile.close();

  if (taskCount == 0)
  {
    cout << "No tasks found\n";
    return;
  }

  for (int i = 0; i < taskCount; i++)
  {
    cout << i + 1 << ". " << tasks[i] << '\n';
  }

  cout << "\n";
}

void addTask()
{
  string tasks[MAX_TASKS];
  int taskCount = 0;

  ifstream MyReadFile("list.txt");

  if (MyReadFile)
  {
    while (getline(MyReadFile, tasks[taskCount]) && taskCount < MAX_TASKS)
    {
      taskCount++;
    }
    MyReadFile.close();
  }

  int numTasks;
  cout << "How many tasks would you like to add?\n";
  cin >> numTasks;
  cin.ignore();

  for (int i = 0; i < numTasks; i++)
  {
    if (taskCount >= MAX_TASKS)
    {
      cout << "Task limit reached!\n";
      return;
    }

    string task = "";
    cout << "Enter a task: ";
    getline(cin, task);

    tasks[taskCount++] = task;
  }

  ofstream MyFile("list.txt");
  if (MyFile.is_open())
  {
    for (int i = 0; i < taskCount; i++)
    {
      MyFile << tasks[i] << "\n";
    }
  }
  else
  {
    cout << "Unable to open file";
  }
}

void deleteTask()
{
  string tasks[MAX_TASKS];
  int taskCount = 0;

  ifstream MyReadFile("list.txt");

  if (!MyReadFile)
  {
    cout << "No tasks found\n\n";
    return;
  }

  while (getline(MyReadFile, tasks[taskCount]) && taskCount < MAX_TASKS)
  {
    taskCount++;
  }

  MyReadFile.close();

  if (taskCount == 0)
  {
    cout << "No tasks found\n";
    return;
  }

  cout << "Current tasks:\n";
  for (int i = 0; i < taskCount; i++)
  {
    cout << i + 1 << ". " << tasks[i] << '\n';
  }

  int taskNumber;
  cout << "Enter the number of the task you want to delete: ";
  cin >> taskNumber;
  cin.ignore();

  if (taskNumber < 1 || taskNumber > taskCount)
  {
    cout << "Invalid task number\n";
    return;
  }

  for (int i = taskNumber - 1; i < taskCount - 1; i++)
  {
    tasks[i] = tasks[i + 1];
  }

  taskCount--;

  ofstream MyWriteFile("list.txt");
  if (MyWriteFile.is_open())
  {
    for (int i = 0; i < taskCount; i++)
    {
      MyWriteFile << tasks[i] << "\n";
    }
  }
  else
  {
    cout << "Unable to open file";
  }

  cout << "Task deleted successfully!\n";
}
