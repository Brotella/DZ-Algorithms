# Программа с алгоритмом сборки кубика-Рубика
Цель работы:
Создать программу реализующую алгоритм сборки кубика-рубика.
Ку́бик Ру́бика (иногда ошибочно — кубик-рубик; первоначально был известен как «магический кубик», венг. bűvös kocka) — механическая головоломка, изобретённая в 1974 году (и запатентованная в 1975 году) венгерским скульптором и преподавателем архитектуры Эрнё Рубиком.
Головоломка представляет собой пластмассовый куб (размер в первоначальном варианте — 3×3×3). Его видимые элементы выглядят как 26 малых кубиков с 54 видимыми цветными гранями, составляющих один большой куб. Грани большого куба способны вращаться вокруг 3 внутренних осей куба. Каждая из шести граней состоит из девяти квадратов и окрашена в один из шести цветов, в одном из распространённых вариантов окраски расположенных парами друг напротив друга: красный — оранжевый, белый — жёлтый, синий — зелёный. Повороты граней позволяют переупорядочить цветные квадраты множеством различных способов. Задача игрока заключается в том, чтобы «собрать кубик Рубика»: поворачивая грани куба, вернуть его в первоначальное состояние, когда каждая из граней состоит из квадратов одного цвета.

Работа программы:

Это программа писалась на языке C++. Вход поступает через stdin. Выход представляет собой последовательность ходов для решения данного куба. 

Теоретическая часть

Кубик Рубика может быть легко собран человеком с использованием метода «Новичок». Этот метод состоит из нескольких независимых этапов. 
Шаг 1: Создайте крест где-нибудь на кубе. Под «крестом» мы подразумеваем решение всех 4 краевых частей определенной грани в правильном положении относительно других граней. 

Уголки: Затем мы собираем каждый из четырех углов на том же слое, где мы построили крест. 

Края: центральные части фиксированы, поэтому для завершения второго слоя куба нам просто нужно собрать 4 краевых части второго слоя. 

OLL: OLL означает Orient Last Layer. Метод новичка разбивает это на 2 шага: сначала мы ориентируем края, затем углы. Это упрощает шаг, поскольку мы можем проверить меньший подраздел возможных случаев (9 случаев, а не 57). 

PLL: Наконец, перестановка последнего слоя или PLL. Снова мы разделим это на два шага, сначала получив углы в правильное положение, а затем сделаем то же самое с краями. Это дает нам 8 случаев для проверки, а не 21. 

Представление работы программы:

Программа использует стандартный алгоритм для движений на кубе. Этот алгоритм состоит из поворота фронтальной грани на 90 градусов по часовой стрелке: R L U D F B. (\ ') означает обратный поворот грани. Например: F 'означает поворот фронтальной грани на 90 градусов против часовой стрелки. 
Чтобы представить состояние куба Рубика, я использую двумерную матрицу [9] [6]. На каждой грани куба есть 9 возможных цветов, и есть 6 граней. Это затрудняет представление поворотов. Я решил запрограммировать каждую функцию вращения в классе Cube. Я не очень понимал, как это сделать, так как когда одна грань движется, цвета на смежных частях тоже движутся. Несмотря на эту проблему с несколько сложной функцией вращения, эта абстракция была очень полезна для разработки метода решения.
Тесты:
Тесты берутся из файлов конце их работы выводиться количество тестов и время их исполнения.

