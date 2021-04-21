#include "educational_divisions.h"
#include "DBeducational_divisions.h"
#include "Intruction.h"
#include <gtest/gtest.h>

#include <string>
TEST(ASD,ASDAGF)
{
EducationalDivisions sad;
sad.SetName("aksd");

sad.SetManager("asdasfx");

sad.SetGraduate_students(105);

sad.SetStaff(25);

std::map<size_t, course_info> rak;
course_info kad;
kad.
students = 1231;
kad.
tuition_fee = 12421;
rak[123]=
kad;
sad.
SetCourse(rak);

std::vector<EducationalDivisions> casd;
casd.
push_back(sad);
DbEducationalDivisions sae;
sae.createDB("name", casd);
}

