# 📝 Task Manager Program

This simple Task Manager program allows users to add, view, and delete tasks stored in a text file (`list.txt`). The program interacts with users through a menu-driven interface that makes task management easy and interactive.

---

## Features ✨

- **Add a Task**: You can add one or more tasks to your task list.
- **View Current Tasks**: Display the list of current tasks stored in the file.
- **Delete a Task**: Remove a specific task by selecting its corresponding number.
- **Exit**: Close the program with a friendly goodbye message.

---

## How It Works 🚀

1. **Menu Display**: When the program starts, you are greeted with a menu offering four options:

   - Add a task
   - View current tasks
   - Delete a task
   - Exit the program

2. **Add Tasks ➕**:

   - The program will prompt you to enter how many tasks you would like to add.
   - After specifying the number, you can type in each task, which will be saved in the `list.txt` file.
   - If you reach the task limit (`100` tasks), the program will notify you and stop adding new tasks.

3. **View Tasks 👀**:

   - If you select this option, it reads the tasks stored in `list.txt` and shows them in the console.
   - If there are no tasks found, it will notify you.

4. **Delete Tasks 🗑️**:

   - You can choose a task to delete by specifying its number from the list.
   - Once a task is deleted, the remaining tasks are shifted up to fill the gap.
   - The updated list of tasks is then saved back into the file.

5. **Exit Program 👋**:
   - Select this option to exit the program with a goodbye message.

---

## How to Run 💻

1. Clone or download this repository to your computer.
2. Compile the C++ program using a C++ compiler:
   ```bash
   g++ -o task_manager task_manager.cpp
   ```
3. Run the program:
   ```bash
   ./task_manager
   ```

---

## Example Usage 🎬

```bash
What would you like to do?
1.) Add a task
2.) See current tasks
3.) Delete a task
4.) Exit program.
> 1
How many tasks would you like to add?
> 2
Enter a task: Finish homework
Enter a task: Clean the house

What would you like to do?
1.) Add a task
2.) See current tasks
3.) Delete a task
4.) Exit program.
> 2
Current tasks:
1. Finish homework
2. Clean the house
```
