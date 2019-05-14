#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../People/CAdvancedStudent.h"
#include "../People/CPupil.h"
#include "../People/CStudent.h"
#include "../People/CTeacher.h"
#include "../People/CWorker.h"

TEST_CASE("Create pupil and check it")
{
	CPupil pupil(
		"Yuriy",
		"Minakov",
		"Yurievich",
		"Sovetskaya 116",
		"Liceum Baumanskiy",
		"10m");

	CHECK(pupil.GetName() == "Yuriy");
	CHECK(pupil.GetSurname() == "Minakov");
	CHECK(pupil.GetPatronymic() == "Yurievich");
	CHECK(pupil.GetAddress() == "Sovetskaya 116");
	CHECK(pupil.GetSchoolName() == "Liceum Baumanskiy");
	CHECK(pupil.GetSchoolClassName() == "10m");
}

TEST_CASE("Create teacher and check it")
{
	CTeacher teacher(
		"Ivan",
		"Ivanov",
		"Ivanovich",
		"Sovetskaya 117",
		"English");

	CHECK(teacher.GetName() == "Ivan");
	CHECK(teacher.GetSurname() == "Ivanov");
	CHECK(teacher.GetPatronymic() == "Ivanovich");
	CHECK(teacher.GetAddress() == "Sovetskaya 117");
	CHECK(teacher.GetSubjectName() == "English");
}

TEST_CASE("Create worker and check it")
{
	CWorker worker(
		"Vasiliy",
		"Pupkin",
		"Ivanovich",
		"Sovetskaya 118",
		"Developer");

	CHECK(worker.GetName() == "Vasiliy");
	CHECK(worker.GetSurname() == "Pupkin");
	CHECK(worker.GetPatronymic() == "Ivanovich");
	CHECK(worker.GetAddress() == "Sovetskaya 118");
	CHECK(worker.GetSpecialty() == "Developer");
}

TEST_CASE("Create student and check it")
{
	CStudent student(
		"Yuriy",
		"Minakov",
		"Yurievich",
		"Sovetskaya 116",
		"VSTU",
		"1170501104");

	CHECK(student.GetName() == "Yuriy");
	CHECK(student.GetSurname() == "Minakov");
	CHECK(student.GetPatronymic() == "Yurievich");
	CHECK(student.GetAddress() == "Sovetskaya 116");
	CHECK(student.GetUniversityName() == "VSTU");
	CHECK(student.GetTicketNumber() == "1170501104");
}

TEST_CASE("Create advanced student and check it")
{
	CAdvancedStudent student(
		"Yuriy",
		"Minakov",
		"Yurievich",
		"Sovetskaya 116",
		"VSTU",
		"1170501104",
		"Cloud technologies");

	CHECK(student.GetName() == "Yuriy");
	CHECK(student.GetSurname() == "Minakov");
	CHECK(student.GetPatronymic() == "Yurievich");
	CHECK(student.GetAddress() == "Sovetskaya 116");
	CHECK(student.GetUniversityName() == "VSTU");
	CHECK(student.GetTicketNumber() == "1170501104");
	CHECK(student.GetDissertationTopic() == "Cloud technologies");
}
