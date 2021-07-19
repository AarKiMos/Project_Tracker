/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
******************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
#include <string>
#include "mini_project.h"
#include "db_util.h"
#include "project.h"
#include "task.h"
#include "employee.h"

using namespace std;

DB *conn;    // the connection
DB_RES *res; // the results
DB_ROW row;  // the row

// initialise DB connector
struct connection_details D;

int main(int argc, char **argv)
{
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
            cout << "login with '-l/--login userId password'"<<endl;
            return 0;
        }
        else
        {
            cout << "Invalid command line args, use -h/--help for help" << endl;
        }
    }
    else //else ask for login credentials
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
    //according to view present options to the user

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

    int loop = 1;
    while (loop)
    {
        cout << "Welcome" << endl;
        cout << "Access level : manager" << endl;
        cout << endl;
        cout << " 1. Show open projects" << endl;
        cout << " 2. Show closed projects" << endl;
        cout << " 3. Add a new project" << endl;
        cout << " 4. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            show_open_projects();
            break;

        case 2:
            show_closed_projects();
            break;

        case 3:
            add_new_project();
            break;

        case 4:
            loop = 0;
            break;

        default:
            break;
        }
    }
}

void employee_view(char *UID)
{

    //Prototypes

    void start_new_task(char*);
    void view_task_at_hand(char*);
    void mark_task_as_completed(char*);

    int loop = 1;
    while (loop)
    {
        cout << "Welcome" << endl;
        cout << "Access level: Employee" << endl;
        cout << endl;
        cout << " 1. Start_next_task" << endl;
        cout << " 2. View current task at hand" << endl;
        cout << " 3. Mark current task at hand as completed" << endl;
        cout << " 4. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            start_new_task(UID);
            break;

        case 2:
            view_task_at_hand(UID);
            break;

        case 3:
            mark_task_as_completed(UID);
            break;

        case 4:
            loop = 0;
            break;

        default:
            break;
        }
    }
}

//Date utility function

string formatDate(struct tm dateObj)
{
    string dateStr = to_string(dateObj.tm_year);
    dateStr.append("-");
    dateStr.append(to_string(dateObj.tm_mon));
    dateStr.append("-");
    dateStr.append(to_string(dateObj.tm_mday));

    return dateStr;
}

struct tm formatDate(string dateObj)
{
    struct tm dateStr;
    dateStr.tm_year = 0;
    dateStr.tm_mon = 0;
    dateStr.tm_mday = 0;
    string::iterator it= dateObj.begin();
    for (int i=0; i<4; i++)
    {
        dateStr.tm_year = dateStr.tm_year*10 + (*it - '0');
        it++;
    }
    it++;
    
    for (int i=0; i<2; i++)
    {
        dateStr.tm_mon = dateStr.tm_mon*10 + (*it - '0');
        it++;
    }
    it++;

    for (int i=0; i<2; i++)
    {
        dateStr.tm_mday = dateStr.tm_mday*10 + (*it - '0');
        it++;
    }

    return dateStr;
}


int calcDTD(string dateStr)
{
    string str = dateStr.substr(8,2);
    int date = stoi(str);
    
    time_t t = time(NULL);
	tm* tPtr = localtime(&t);
    
    int dtd = tPtr->tm_mday - date;
    return dtd;    
}

// Task management functions

void add_new_task(int new_task_pid)
{
    DB *local_conn;
    DB_RES *result;
    DB_ROW row;

    local_conn = db_connection_setup(D);
    char query[] = "Select MAX(TID) from task;";
    result = db_perform_query(local_conn, query);
    row = mysql_fetch_row(result);
  
    task new_task;
    string new_task_name;
    struct tm new_task_dd;

    cout<<"Enter name of Task"<<endl;
    cin>>new_task_name;
    cout<<"Enter deadline of task (DD MM YYYY)"<<endl;
    cin>>new_task_dd.tm_mday>>new_task_dd.tm_mon>>new_task_dd.tm_year;


    string ddStr = formatDate(new_task_dd);


    new_task.set_PID(new_task_pid);
    new_task.set_ID(atoi(row[0])+1);
    new_task.set_name(new_task_name);
    new_task.set_deadline(new_task_dd);

    db_free_result(result);


    char query2[100]; 

    sprintf(query2, "Insert into task values (%d, %d, '%s', '%s', %d);",new_task_pid, new_task.get_ID(), new_task.get_name().c_str(), ddStr.c_str(), 0);

    result = db_perform_query(local_conn, query2);

    db_close(local_conn);

}

void start_new_task(char* t_eid)
{
    DB *local_conn;
    DB_RES *result;
    DB_ROW row;
    local_conn = db_connection_setup(D);

    priority_queue<task, vector<task>, task_comparator> task_queue;

    char query[] = "Select * from task where is_complete = 1;";

    result = db_perform_query(local_conn, query);

    while((row = mysql_fetch_row(result)) != NULL)
    {
 
        task new_task;
 
        new_task.set_PID(atoi(row[0]));
        new_task.set_ID(atoi(row[1]));
        new_task.set_name(row[2]);
        new_task.set_deadline(formatDate(row[3]));
        new_task.dtd = calcDTD(row[3]);
        new_task.status = 1;

        task_queue.push(new_task);
    }

    task T = task_queue.top();

    db_free_result(result);

    char temp[5];
    sprintf(temp, "%d", T.get_PID());
    
    char query4[100];
    sprintf(query4, "Insert into assign values (%s, %d, %d);",t_eid, T.get_PID(), T.get_ID());
    result = db_perform_query(local_conn, query4);

    sprintf(temp, "%d", T.get_ID());
    char query2[] = "update task set is_complete = 2 where tid = ";
    strcat(query2, temp);
    strcat(query2, ";");

    result = db_perform_query(local_conn, query2);

    db_close(local_conn);
}

void view_task_at_hand(char* eid)
{
    DB *local_conn;
    DB_RES *res;
    DB_ROW row;
    local_conn = db_connection_setup(D);

    char query[] = "Select t.tid, t.name from task t, assign ag where ag.tid = t.tid and eid =";
    strcat(query, eid);
    strcat(query, ";");

    res = db_perform_query(local_conn, query);
    if((row = mysql_fetch_row(res)) != NULL)
    {
        cout<<"Task Id | Task Name";
        cout<<endl<<row[0]<<" | "<<row[1];
    }
    else
    {
        cout<<"No task assigned"<<endl;
    }
    cout<<endl<<endl;
    db_free_result(res);

    db_close(local_conn);
}

void mark_task_as_completed(char* eid)
{
    DB *local_conn;
    DB_RES *result;
    DB_ROW row;

    local_conn = db_connection_setup(D);

    char query[] = "Select TID from assign where EID = ";
    strcat(query, eid);
    strcat(query, ";");

    result = db_perform_query(local_conn, query);
    row = mysql_fetch_row(result);

    char t_tid[5];
    strcpy(t_tid, row[0]);

    db_free_result(result);

    char query2[] = "Update task set is_complete = 3 where TID = ";
    strcat(query2, t_tid);
    strcat(query2, ";");
   
    result = db_perform_query(local_conn, query2);

    char query3[] = "delete from assign where TID = ";
    strcat(query3, t_tid);
    strcat(query3, ";");
    result = db_perform_query(local_conn, query3);

    char query4[100];
    sprintf(query4, "Select * from task where TID = (%d + 1) and PID = (select PID from task where TID = %s);", atoi(t_tid), t_tid);
    result = db_perform_query(local_conn, query4);

    DB *local_conn_2;
    local_conn_2 = db_connection_setup(D);

    if((row = mysql_fetch_row(result)) == NULL)
    {
        char query5[100];
        sprintf(query5, "update project set is_complete = 1 where PID = (select PID from task where TID = %s);", t_tid);
        result = db_perform_query(local_conn_2, query5);
    }
    else
    {
        char query5[100];
        sprintf(query5, "update task set is_complete = 1 where TID = (%d + 1) and PID = (select PID from task where TID = %s);", atoi(t_tid), t_tid);
        result = db_perform_query(local_conn_2, query5);
    }

    db_free_result(result);
    db_close(local_conn);
    db_close(local_conn_2);
}


void add_new_project()
{
    DB *local_conn;
    DB_RES *result;
    DB_ROW row;

    local_conn = db_connection_setup(D);
    char query[] = "Select MAX(PID) from project;";
    result = db_perform_query(local_conn, query);
    row = mysql_fetch_row(result);
  
    project new_proj;
    string new_proj_name;
    struct tm new_proj_dd;
    int task_count = 0;

    cout<<"Enter name of project"<<endl;
    cin>>new_proj_name;
    cout<<"Enter deadline of project (DD MM YYYY)"<<endl;
    cin>>new_proj_dd.tm_mday>>new_proj_dd.tm_mon>>new_proj_dd.tm_year;

    string ddStr = formatDate(new_proj_dd);

    new_proj.set_ID(atoi(row[0])+1);
    new_proj.set_name(new_proj_name);
    new_proj.set_deadline(new_proj_dd);

    int it = 1;
    while(it)
    {
        task_count++;
        add_new_task(new_proj.get_ID());
        cout<<"Add new task? (1/0)"<<endl;
        cin>>it;
    }

    // while((row = mysql_fetch_row(result)) != NULL) {}
    db_free_result(result);

    char query2[100];
    sprintf(query2, "Insert into project values (%d, '%s', '%s', %d, %d);",new_proj.get_ID(), new_proj.get_name().c_str(), ddStr.c_str(), 0, task_count);

    db_perform_query(local_conn, query2);
    db_close(local_conn);
}


void show_open_projects()
{
    DB *local_conn;
    DB_RES *result;
    DB_ROW row;
    local_conn = db_connection_setup(D);

    stack<project> st;
    char query[] = "Select * from project;";
    result = db_perform_query(local_conn, query);

    while((row = mysql_fetch_row(result)) != NULL)
    {
        if(!strcmp(row[3],"0"))
        {
            project P;
            P.set_ID(atoi(row[0]));
            P.set_name(row[1]);
            P.set_deadline(formatDate(row[2]));
            P.is_complete = 0;
            P.task_count = atoi(row[5]);
        
            st.push(P);
        }
    }
    
    cout<<"Open projects:- "<<endl;
    cout<<endl;
    cout<< "ID | Name | Deadline"<<endl<<endl;

    while(!st.empty())
    {
        project P = st.top();
        cout<<P.get_ID()<<" | "<<P.get_name()<<" | "<<formatDate(P.get_deadline())<<endl;
        st.pop();
    }

    db_free_result(result);
    db_close(local_conn);
}

void show_closed_projects()
{
    DB *local_conn;
    DB_RES *result;
    DB_ROW row;
    local_conn = db_connection_setup(D);
    
    stack<project> st;
    char query[] = "Select * from project;";
    result = db_perform_query(local_conn, query);

    while((row = mysql_fetch_row(result)) != NULL)
    {
        if(!strcmp(row[3],"1"))
        {
            project P;
            P.set_ID(atoi(row[0]));
            P.set_name(row[1]);
            P.set_deadline(formatDate(row[2]));
            P.is_complete = 1;
            P.task_count = atoi(row[5]);
        
            st.push(P);
        }
    }
    
    cout<<"Closed projects:- "<<endl;
    cout<<endl;
    cout<< "ID | Name | Deadline"<<endl<<endl;

    while(!st.empty())
    {
        project P = st.top();
        cout<<P.get_ID()<<" | "<<P.get_name()<<" | "<<formatDate(P.get_deadline())<<endl;
        st.pop();
    }

    db_free_result(result);
    db_close(local_conn);
}