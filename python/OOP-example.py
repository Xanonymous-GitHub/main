from abc import ABC, abstractmethod


class Students():

    def __init__(self, last_name="", first_name="", telephone="", department="", score=-1):
        self.__last_name = last_name
        self.__first_name = first_name
        self.__telephone = telephone
        self.__department = department
        self.__score = score

    def __str__(self):
        return self.to_string
    __repr__ = __str__

    @property
    def to_string(self):
        return str(' '.join([self.__first_name,
                             self.__last_name,
                             self.__telephone,
                             self.__department,
                             self.__GET_SCORE(self.__score)]))

    @property
    def last_name(self):
        return self.__last_name

    @property
    def first_name(self):
        return self.__first_name

    @property
    def telephone(self):
        return self.__telephone

    @property
    def department(self):
        return self.__department

    @property
    def score(self):
        return self.__GET_SCORE(self.__score)

    def __GET_SCORE(self, data):
        return data if data != -1 else self.__first_name+" Not have score yet!"

    @last_name.setter
    def last_name(self, new_last_name):
        if type(new_last_name) == str:
            self.__last_name = new_last_name
        else:
            raise TypeError("Wrong parameter type!")

    @first_name.setter
    def first_name(self, new_first_name):
        if type(new_first_name) == str:
            self.__first_name = new_first_name
        else:
            raise TypeError("Wrong parameter type!")

    @telephone.setter
    def telephone(self, new_telephone):
        if type(new_telephone) == str:
            self.__telephone = new_telephone
        else:
            raise TypeError("Wrong parameter type!")

    @department.setter
    def department(self, new_department):
        if type(new_department) == str:
            self.__department = new_department
        else:
            raise TypeError("Wrong parameter type!")

    @score.setter
    def score(self, new_score):
        if type(new_score) == (int or float):
            self.__score = new_score
        else:
            raise TypeError("Wrong parameter type!")

    @property
    @abstractmethod
    def pass_fail(self):
        pass


class Undergraduates(Students):
    def __init__(self, last_name="", first_name="", telephone="", department="", score=-1):
        super().__init__(last_name, first_name, telephone, department, score)

    @property
    def pass_fail(self):
        tmp = self.score
        return ("pass!" if tmp >= 60 else "failed!")if type(tmp) == int else tmp


class Graduates(Undergraduates):
    def __init__(self, last_name="", first_name="", telephone="", department="", score=-1):
        super().__init__(last_name, first_name, telephone, department, score)

    @property
    def pass_fail(self):
        tmp = self.score
        return ("pass!" if tmp >= 70 else "failed!")if type(tmp) == int else tmp


def main():
    # init object
    david = Students("Jiang", "Da-Wei", "0987187487", "NTUT-1")
    ricky = Undergraduates("Hu", "Ricky", "09487332556", "NTUT-2")
    xanonymous = Graduates("Lin", "Tien-Yu", "0923458965", "Apple-CEO")
    # getters example
    print(david.to_string)
    print(ricky.to_string)
    print(xanonymous.pass_fail)
    print(david.pass_fail)
    print(xanonymous.to_string)
    print(xanonymous)  # equal to "print(xanonymous.to_string)"
    print(david.first_name)
    print(ricky.last_name)
    print(xanonymous.department)
    # setters example
    xanonymous.score = 100
    try:
        xanonymous.score = "87"  # "score" is a int not a str
    except Exception as e:
        print(e)
    david.score = 0
    ricky.first_name = "putin"
    # now we see the data again using getters
    print(xanonymous.pass_fail)
    print(david.pass_fail)
    print(ricky.first_name)


if __name__ == '__main__':
    main()
