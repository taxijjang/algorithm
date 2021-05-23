class Employee:
    def calculatePay(self):  # CFO
        # CFO는 새로운 업무시간 계산 방식 원함
        work_time = self.reportHours(20)

    def reportHours(self):  # COO
        # COO는 기존 업무시간 계산 방식 원함
        work_time = self.reportHours(20)

    def save(self):  # CTO
        pass

    def regularHours(self, time):  # CFO, COO
        # work_time = timm * 30  # old code
        work_time = time * 30 * 4  # new code
        return work_time


###
class EmployeeData:
    pass


###
class PayCaculator(EmployeeData):
    def calculatePay(self):
        pass


class HourReporter(EmployeeData):
    def reportHours(self):
        pass


class EmployeeSaver(EmployeeData):
    def saveEmployee(self):
        pass


###
class EmployeeFacade:
    def calculatePay(self):
        return PayCaculator.calculatePay()

    def reportHours(self):
        return HourReporter.reportHours()

    def save(self):
        return EmployeeSaver.saveEmployee()


###
class HourRepoter:
    def reportHours(self):
        pass


class EmployeeSaver:
    def saveEmployee(self):
        pass


###
class EmployeeData:
    def __init__(self):
        self.employeeData = None

    def calculatePay(self):
        pass

    def reportHours(self):
        return HourReporter.reportHours()

    def save(self):
        return EmployeeSaver.saveEmployee()

###
# OCP를 지키지 못한 예제
class Message:
    def __init__(self, data):
        self.data = data

class FirstGrade(Message):
    pass

class SecondGrade(Message):
    pass

class DefaultGrade(Message):
    pass

class GradeMessageClassification:
    # Grade에 따른 메시지 분류
    def __init__(self, data):
        self.data = data

    def classification(self):
        if (self.data == 1):
            return FirstGrade(self.data)
        elif (self.data == 2):
            return SecondGrade(self.data)
        else:
            return DefaultGrade(self.data)
# ###
class Message:
    def __init__(self, data):
        self.data = data
    @staticmethod
    def is_collect_grade_message(data: dict):
        return False

class FirstGrade(Message):
    @staticmethod
    def is_collect_grade_message(data):
        return data['grade'] == 1

class SecondGrade(Message):
    @staticmethod
    def is_collect_grade_message(data):
        return data['grade'] == 2

class ThirdGrade(Message):
    @staticmethod
    def is_collect_grade_message(data):
        return data['grade'] == 3

class DefaultGrade(Message):
    pass

class GradeMessageClassification():
    def __init__(self, data):
        self.data = data

    def classification(self):
        for grade_message_class in Message.__subclasses__():
            if grade_message_class.is_collect_grade_message(self.data):
                return grade_message_class(self.data)
            return DefaultGradeMessage(self.data)

if __name__ =="__main__":
    grade = GradeMessageClassification({'grade':1})
    print(grade.classification())