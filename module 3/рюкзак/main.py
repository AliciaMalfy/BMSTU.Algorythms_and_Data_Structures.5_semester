import sys
import re


class Packsack(object):
    items = []
    capacity = 0
    sum_of_cost = 0
    sum = 0
    result = 0
    mas = []
    dop_mas = []

    def set_size(self, info):
        self.capacity = info

    def append_item(self, info):
        self.items.append(info)

    def nod(self, x, y):
        if (x == 0) or (y == 0):
            return max(x, y)
        elif x > y:
            return self.nod(x - y, y)
        else:
            return self.nod(x, y - x)

    def sum_nod(self):
        self.result = int(max(self.items)[0])
        for i in range(1, len(self.items)-1):
            if self.result > self.nod(int(self.items[i][0]), int(self.items[i+1][0])):
                self.result = self.nod(int(self.items[i][0]), int(self.items[i+1][0]))

    def suitable_items(self):
        self.capacity = int(self.capacity / self.result)
        for i in range(1, len(self.items)):
            self.items[i][0] = int(int(self.items[i][0]) / self.result)

    def search(self, m, n):
        if self.mas[m][n] == 0:
            return
        if self.mas[m - 1][n] == self.mas[m][n]:
            self.search(m - 1, n)
        else:
            self.search(m - 1, n - int(self.items[m - 1][0]))
            self.dop_mas.append(m)

    def matrix(self):
        self.items.pop(0)
        self.mas = [[0 for i in range(self.capacity + 1)] for j in range(len(self.items) + 1)]
        for i in range(1, len(self.items) + 1):
            for j in range(1, self.capacity + 1):
                if j < int(self.items[i - 1][0]):
                    self.mas[i][j] = self.mas[i - 1][j]
                else:
                    self.mas[i][j] = max(self.mas[i - 1][j], self.mas[i - 1][j - int(self.items[i - 1][0])] + int(self.items[i - 1][1]))
        self.sum_of_cost = int(self.mas[len(self.items)][self.capacity])
        self.search(len(self.items), self.capacity)

    def weight(self):
        for i in range(0, len(self.items)):
            for j in self.dop_mas:
                if j - 1 == i:
                    self.sum = self.items[i][0] + self.sum

    def print_r(self):
            print(str(self.result * self.sum) + " " + str(self.sum_of_cost))

    def answer(self):
        for i in self.dop_mas:
            print(i)

TF = False
number = Packsack()

for stroka in sys.stdin:
    access_stroka = re.findall(r'\d+', stroka)
    if len(access_stroka) > 0:
        if TF:
            number.set_size(int(access_stroka[0]))
            TF = True
        elif not TF:
            number.append_item(access_stroka)
number.nod()
number.suitable_items()
number.matrix()
number.weight()
number.print_r()
number.answer()
