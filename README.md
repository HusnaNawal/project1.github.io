# project1.github.io

Mini Project: STUDENT ATTENDANCE MANAGEMENT SYSTEM

Student Attendance Management System is a system that is used by the lecturer to key in the student attendance for every class , every day. This system is created 
to make the lecturers’ wok easier and keep the student attendance up-to-date. This system also allows lecturer to insert and delete students’ details if there is any 
wrong information. This system will exchange the manual system, which is complicated and harder like using manual record. 

Student Attendance Management System is a secure system because only those who has authority can login to the system. That is means, only lecturer or admin that
has password to the account can open or login to the system. By using this system, the lecturer can display all the students’ list and details about their attendance 
at the end of the semester. Students who are absent for more than 3 days without valid or reasonable reasons will be sent warning letter to their parents and will be 
barred from taking the final examination.

This system is using queue to insert or delete student information. Admin or lecturer can search for student by using their ID because, if we use student name, there 
is a possibility that more than one student has  the same name. Furthermore, ID is unique and no other student can have the exact same ID.

Although it can be used to take part in this student attendance management scheme, it has many more useful features. It is so useful that it can also be used in 
schools and in corporate training centres. To make the learning process as smooth as possible, you can handle various content-rich catalogs with it. To make the 
learning process even more enjoyable it supports through languages.

Pro:
-	This will integrate very likely with third party applications
-	Can be personalized in several ways to provide various types of content
-	Simple to scale, with fantastic features and flexible prices
Cons:
-	Integrations will often not go as expected
-	Particularly for beginners a steep learning curve exists

In this student attendance management system, we have:

	Login interface.
-	Admin or user need to log in to the system first before go through the menu. The default password for our system is”abc123” and the default user name is 
“admin2020”. When the admin key in the password, our system will compare it to the default one. If the password match, the message “Logged in successful” will be 
displayed and the system will allow the admin to login and go to menu interface and if the password is not match  the message “Sorry Login is unsuccessful” will be  
displayed and the user need to re-enter username and password. User cannot re-enter password and more than four times. If the user keeps enter the wrong password 
for more than four times, message “Sorry you have entered the wrong username and password for four times!!!” will be displayed as a warning to the user. In this 
system, we use nested structure which are struct User and struct node.

	Menu interface.
-	 After the user successfully login to the system, the menu interface will appear and message like “Student Attendance Management System “will be displayed. The
purpose of this menu interface is to guide the user what can they do when there are using our system. In this system, user can insert, delete, list, search and 
even sort the student information.


	Insert student details for every class.
- We use enqueue (insert at the end of linked list) to insert students’ details. The new data will become the last node in the linked list. 
- Students’ details such as name, ID, subject and section and date can be stored in the system database.


	Delete wrong students’ details.
-we use dequeue (delete at the beginning of linked list) when user want to delete any information about student. The dequeue function will delete any data that 
is inserted at first. If there is no data has been inserted, the message “The student list is empty. Cannot delete!” will be displayed.

	Display student list (sorted by section)
The function selection sort will display students list based on section. The section will be display from the lowest which is sec 01 to 05. 
This system also will display all student information such as name, id, section, date and subject regardless their section.

	Search student
-	The user can search any student by using student ID. Student ID is unique and more specific.

	Exit
-	The user can choose exit if they are already done using the system but need to log in again after exit.

This system has been developed by using c language. In order to run the code any compiler such as codeblock, visual studio, and so on can be used.

