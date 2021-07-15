/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Aachman Mittal 9919103218
******************************************************************************/
#include <iostream>
// #include <fstream>
#include <cstring>
#include "mini_project.h"
#include "db_util.h"
#include "project.h"
#include "department.h"
#include "task.h"
#include "employee.h"



using namespace std;

DB *conn;    // the connection
DB_RES *res; // the results
DB_ROW row;  // the row

void login(char *UID, char *pass)
{
    char *query = strcat("select * from user where UID = ", UID);
    strcat(query, ";");

    res = db_perform_query(conn, query);

    if ((row = mysql_fetch_row(res)) == NULL)
    {
        cout << "ERROR: User not found, exiting";
        exit(1);
    }
    else if (row[1] == pass)
    {
        if (row[2] == "root")
        {
            root_view();
        }
        else if (row[2] == "manager")
        {
            manager_view(UID);
        }
        else if (row[2] == "employee")
        {
            employee_view(UID);
        }
    }
    else 
    {
        cout<<"!!!! Wrong Password for user "<< UID <<" !!!!"<<endl;
        exit(0);
    }
}


void root_view() 
{
    
    // choice
    int loop = 1;

    while(loop)
    {
        cout<<"Welcome Root User"<<endl;
        cout<<endl;
        cout<<" 1. Add a new employee (user)"<<endl;
        cout<<" 2. Remove an employee (user account)"<<endl;
        cout<<" 3. Genreate a list of all the employees"<< endl;
        cout<<" 4. Generate a list of all the projects"<<endl;
        cout<<" 5. Exit"<<endl;
        int choice;
        cin>>choice;

        switch (choice)
        {
        case 1:
            //new_employee();
            break;
        
        case 2:
            //remove_employee();
            break;

        case 3:
            //list_employees();
            break;
        
        case 4:
            //list_projects();
            break;

        case 5:
            loop = 0;
            break;

        default:
            break;
        }
    }
    
    // list of employees ()
    // list of projects ()
    // add user account ()
    // remove account ()
}


void manager_view(char* UID)
{
    emp current_user;
    char query[] = "select * from employee where EID = ";
    strcat(query, UID);
    strcat(query, ";");

    res = db_perform_query(conn, query);

    //copy values in current_user

    // view open projects()
    // view closed projects ()
    // add a project()
    // remove a project()
    int loop = 1;
    while(loop)
    {
        cout<<"Welcome Root User"<<endl;
        cout<<endl;
        cout<<" 1. Show open projects"<<endl;
        cout<<" 2. Show closed projects)"<<endl;
        cout<<" 3. Add a new project"<< endl;
        cout<<" 4. Delete a project"<<endl;
        cout<<" 5. Exit"<<endl;
        int choice;
        cin>>choice;

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
            loop = 0;
            break;

        default:
            break;
        }
    }
}

void employee_view(char* UID)
{
    emp current_user;
    char query[] = "select * from employee where EID = ";
    strcat(query, UID);
    strcat(query, ";");

    res = db_perform_query(conn, query);

    // pick task from queue()
    // view current task in hand()
    // mark current task as finished()
    // add a remark to current project()

    int loop = 1;
    while(loop)
    {
        cout<<"Welcome Root User"<<endl;
        cout<<endl;
        cout<<" 1. Start_next_task"<<endl;
        cout<<" 2. View current task at hand"<<endl;
        cout<<" 3. Mark current task at hand as completed"<< endl;
        cout<<" 4. Add a remark to project at hand"<<endl;
        cout<<" 5. Exit"<<endl;
        
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            //start_new_task();
            break;
        
        case 2:
            //view_task_at_hand();
            break;

        case 3:
            //make_task_as_complete();
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









int main(int argc, char **argv)
{

    // initialise DB connector
    struct connection_details D;
    D.database = "week1b";
    D.user = "aarkimos";
    D.password = "password1";
    D.server = "localhost";

    conn = db_connection_setup(D);

    // Parse command line args for uid and password
    if (argc > 1) //if args present login
    {
        if (strcmp(argv[1], "-l") || strcmp(argv[1], "--login"))
        {
            char *uid = argv[2], *pass = argv[3];
            login(uid, pass);
        }
        else if (strcmp(argv[1], "-h") || strcmp(argv[1], "--help"))
        {
            // TODO: Display a help message
            return 0;
        }
        else
        {
            cout << "Invalid command line args, use -h/--help for help" << endl;
        }
    }
    else //else ask for login credentials
    {
        char *uid, *pass;
        cout<<endl<<endl;
        cout<<"Enter User ID: "<<endl;
        cin>>uid;
        cout<<"Enter Password"<<endl;
        cin>>pass;
        cout<<"endl";

        login(uid, pass);

    }

    //login and call view accordingly
    //according to view query the database and present options to the user

    db_close(conn);

    return 0;
}