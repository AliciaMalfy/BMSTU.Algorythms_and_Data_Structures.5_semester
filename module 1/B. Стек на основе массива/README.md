# Задание

```
Реализуйте стек, используя только массив.
```

*Формат входных данных*
```
На стандартном потоке ввода задаётся последовательность команд. Пустые строки игнорируются. Первая
строка всегда содержит "set_size N", где N - максимальный размер стека, целое число.
Каждая последующая строка содержит ровно одну команду: push X, pop или print, где X - произвольная
строка без пробелов.
```

*Формат результата*
```
Команда print выводит содержимое стека (снизу вверх) одной строкой, значения разделяются пробелами.
Если стек пуст, то выводится "empty". В случае переполнения стека выводится "overflow". Команда pop
выводит элемент или "underflow", если стек пуст. Память под стек должна быть выделена не более одного
раза, при вызове команды "set_size". В любой непонятной ситуации результатом работы любой команды
будет "error".
```
Результат работы программы выводится в стандартный поток вывода.
