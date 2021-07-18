/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Aachman Mittal 9919103218
******************************************************************************/
#include <iostream>
// #include <fstream>
#include <cstring>
#include <cstdlib>
#include "mini_project.h"
#include "db_util.h"
#include "project.h"
#include "task.h"
#include "employee.h"

using namespace std;

DB *conn;    // the connection
DB_RES *res; // the results
DB_ROW row;  // the row

int main(int argc, char **argv)
{

    // initialise DB connector
    struct connection_details D;
    D.database = "mini_project";
    D.user = "aarkimos";
    D.password = "password1";
    D.server = "localhost";

    conn = db_connection_setup(D);

    // Parse command line args for uid and password
    if (argc > 1) //if args present login
    {
        if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "--login"))
        {
            char *uid = argv[2], *pass = argv[3];
            login(uid, pass);
        }
        else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        {
            // TODO: Display a help message
            return 0;
        }
        else
        {
            cout << "Invalid command line args, use -h/--help for help" << endl;
        }
    }
    else //else ask for login credentialssd
    {
        char uid[5], pass[10];
        cout << endl
             << endl;
        cout << "Enter User ID: " << endl;
        cin.getline(uid, 5, '\n');
        cout << "Enter Password" << endl;
        cin.getline(pass, 10, '\n');
        cout << endl;

        login(uid, pass);
    }

    //login and call view accordingly
    //according to view query the database and present options to the user

    db_close(conn);

    return 0;
}


void login(char *UID, char *pass)
{
    char query[] = "select * from user where UID = ";
    strcat(query, UID);
    strcat(query, ";");

    res = db_perform_query(conn, query);

    if ((row = mysql_fetch_row(res)) == NULL)
    {
        cout << "ERROR: User not found, exiting";
        exit(1);
    }
    else if (!strcmp(row[1], pass))
    {
        if (!strcmp(row[2],"manager"))
        {
            manager_view(UID);
        }
        else if (!strcmp(row[2],"employee"))
        {
            employee_view(UID);
        }
    }
    else
    {
        cout << "!!!! Wrong Password for user " << UID << " !!!!" << endl;
        exit(0);
    }
}

void manager_view(char *UID)
{
    //prototypes

    void show_open_projects();
    void show_closed_projects();
    void add_new_project();
    void delete_a_project();
    void new_employee();
    void remove_employee();
    void list_employees();

    emp current_user;
    char query[] = "select * from user where UID = "; //later change to employee table
    strcat(query, UID);
    strcat(query, ";");

    db_free_result(res);
    res = db_perform_query(conn, query);

    //TODO: 

    //copy values in current_user
    // view open projects()
    // view closed projects ()
    // add a project()
    // remove a project()
    // list of employees ()
    // add user account ()
    // remove account ()
    
    
    int loop = 1;
    while (loop)
    {
        cout << "Welcome" << endl;
        cout << "Access level : manager" << endl;
        cout << endl;
        cout << " 1. Show open projects" << endl;
        cout << " 2. Show closed projects" << endl;
        cout << " 3. Add a new project" << endl;
        cout << " 4. Delete a project" << endl;
        cout << " 5. Add a new employee (user)" << endl;
        cout << " 6. Remove an employee (user)" << endl;
        cout << " 7. Genreate a list of all the employees" << endl;
        cout << " 8. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            //show_open_projects();
            break;

        case 2:
            //show_closed_projects();
            break;

        case 3:
            //add_new_project();
            break;

        case 4:
            //delete_a_project();
            break;
        
        case 5:
            //new_employee();
            break;

        case 6:
            //remove_employee();
            break;

        case 7:
            //list_employees();
            break;

        case 8:
            loop = 0;
            break;

        default:
            break;
        }
    }
}

void employee_view(char *UID)
{
    emp current_user;
    char query[] = "select * from user where UID = "; //later change to employee table
    strcat(query, UID);
    strcat(query, ";");

    db_free_result(res);
    res = db_perform_query(conn, query);

    //TODO: 

    // copy values in current_user
    // pick task from queue()
    // view current task in hand()
    // mark current task as finished()
    // add a remark to current project()

    int loop = 1;
    while (loop)
    {
        cout << "Welcome" << endl;
        cout << "Access level: Employee" << endl;
        cout << endl;
        cout << " 1. Start_next_task" << endl;
        cout << " 2. View current task at hand" << endl;
        cout << " 3. Mark current task at hand as completed" << endl;
        cout << " 4. Add a remark to project at hand" << endl;
        cout << " 5. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            //start_new_task();
            break;

        case 2:
            //view_task_at_hand();
            break;

        case 3:
            //mark_task_as_complete();
            break;

        case 4:
            //add_remark();
            break;

        case 5:
            loop = 0;
            break;

        default:
            break;
        }
    }
}


// Functions called from within views

void new_employee()
{
    char query[] = "Select MAX(EID) from employee;";
    res = db_perform_query(conn, query);
    row = mysql_fetch_row(res);
    
    emp new_emp;
    string new_emp_name;

    cout<<"Enter name of employee"<<endl;
    cin>>new_emp_name;

    new_emp.set_ID(atoi(row[0])+1);
    new_emp.set_name(new_emp_name);

    char *query2;
    sprintf(query2, "Insert into employee values (%d, '%s');",new_emp.get_ID(), new_emp.get_name() );
    
    
}
