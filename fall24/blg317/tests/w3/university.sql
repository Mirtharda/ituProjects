create database UNIVERSITY;
use UNIVERSITY;

create table DEPARTMENT (
		dept_id		varchar(5) primary key,
        dept_name 	varchar(50),
        building 	varchar(5)
);

create table COURSE (
		course_id 	varchar(10) primary key,
        course_title varchar(30),
        dept_id 	varchar(5),
        credits 	smallint CHECK (credits>=0),
		foreign key (dept_id) references department (dept_id)
								ON DELETE SET NULL
);

create table INSTRUCTOR (
		instructor_id	varchar(5) primary key,
        instructor_name	varchar(20)
						NOT NULL,
        dept_id			varchar(5),
        foreign key (dept_id) references department (dept_id)
						ON DELETE SET NULL
);        

create table STUDENT (
		student_id		varchar(50) primary key,
        student_name 	varchar(20)
						NOT NULL,
		dept_id			varchar(5),
        total_credits	int CHECK (total_credits >= 0),
        foreign key (dept_id) references department (dept_id)
						ON DELETE SET NULL
);

create table TEACHES (
		CRN				int UNIQUE,
        instructor_id	varchar(5),
        course_id   	varchar(10),
		year_semester	varchar(15), 
        primary key (instructor_id, course_id),
        foreign key (instructor_id) references 
					instructor (instructor_id),
		foreign key (course_id) references 
					course (course_id)
);

create table TAKES (
		student_id		varchar(5),
        CRN				smallint,
        grade 			varchar(2),
        primary key (student_id, CRN),
        foreign key (student_id) references 
					student (student_id),
		foreign key (CRN) references
					teaches (CRN)
);


insert into DEPARTMENT values
			('BIO', 'Biology', 'Watson Bld.'),
            ('CS', 'Computer Science', 'Taylor Bld.'),
            ('EE', 'Electronic Eng.', 'Taylor Bld.'),
            ('FIN', 'Finance', 'Painter Bld.'),
            ('HIS', 'History', 'Painter Bld.'),
            ('MU', 'Music', 'Packard Bld.'),
            ('PHY', 'Physics', 'Watson Bld.'),
            ('SPR', 'Sports', 'NULL');
            
insert into COURSES values
			('BIO-101', 'Intro. to Biology', 'BIO', 4),
            ('BIO-301', 'Molecular Biology', 'BIO', 4),
            ('BIO-401', 'Biology Lab', 'BIO', 3),
            ('CS-101', 'Intro. to Algorithms', 'CS', 4),
            ('CS-190', 'Web Design', 'CS', 4),
            ('CS-315', 'Robotics', 'CS', 3),
            ('CS-319', 'Image Processing', 'CS', 3),
            ('CS-347', 'Database System Concepts', 'CS', 3),
            ('EE-184', 'Intro. to Digital Systems', 'EE', 3),

create table student_course
	(student_name	varchar(20),
    course_title	varchar(30),
    grade			varchar(2));
    
insert into student_course
select student_name, course_title, grade
from student, takes, teaches, course
where student.student_id   	= takes.student_id AND
		takes.CRN 			= teaches.CRN		AND
        teaches.course_id	=course.course_id
order by student_name;