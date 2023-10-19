Documentation

Project name:- Department Student Information System.

    	Introduction:- Department student information system is a C-based project where student can add their information but 
     they cannot add their CGPA. There is a authority only who can add the student CGPA.
     
    The file will store the following information for each student:-
    1.	Roll Number
    2.	Name
    3.	Contact Number
    4.	Password
    5.	Batch
	Key Component:-

    •	Authority:- There is an authority who can see all the details of the student and who can add and update the CGPA of the students. The authority can add student by Roll number. By using this roll number he/she can see batch wise student information or individual information of a student. The authority has a name and a password. By matching name and password the admin can do this following things:-
           1. Add a student
           2. Update CGPA
           3. Batch wise Info
           4. Individual Info
           5. Reset
           6. Exit

    •	Fill Information:- When authority add a student, this student can add his information. Otherwise, he cannot able to 
      fill his information. The student can fill their roll number, name, contact number, create their own password and  
      batch number.

    •	Log in to your account:- When a student fill his information then he can log in to his account with his roll number 
      and password. When the roll number and password matching then he can see his individual information and update his 
      password also.
    	Project Structure:-
     •	The project consists of a single C source file.
     •	It includes standard C libraries like <stdio.h>, <string.h>, and <stdlib.h> for various functionalities.

    	Function:- The project contains several functions, each responsible for specific tasks:
      •	authority:- manage student information and update CGPA.
      •	add:- manage to add a student by authority
      •	fill_info:- manage to add information by a student
      •	login:- manage to log in by a student
      •	change_p:- manage to change password by a student
      •	update_cgpa:- manage to update cgpa by the authority.
      •	info:- to get students roll number
      •	print:- to get students batch number

    	Error Handling:
    The project includes error handling for various scenarios, such as file I/O errors and insufficient student information.

    	Future improvements:- The project is a representation of student information of the department. Where the student can 
     easily see their personal information and CGPA. This project will be improve by different ways:-
    •	Add more features like the ability to generate transcripts, send email notifications to students and faculty, and 
      track student progress towards graduation.
    •	Make the system more user friendly.
    •	Use mobile technology.
    •	Support for multiple users.

    	Conclusion:- This project documentation has described the requirements, design, implementation, and testing of a 
      department student information system. The system will be a valuable asset to the department, providing a central 
      location to manage all aspects of student information.


