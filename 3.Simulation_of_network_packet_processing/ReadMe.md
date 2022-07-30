Ваша цель — реализовать симулятор обработки сетевых пакетов.
Для i-го пакета известно время его поступления arrivali, а также время durationi, необходимое на его обработку.
В вашем распоряжении имеется один процессор, который обрабатывает пакеты в порядке их поступления.
Если процессор начинает обрабатывать пакет i (что занимает время durationi), он не прерывается и не останавливается до тех пор, пока не обработает пакет.
У компьютера, обрабатывающего пакеты, имеется сетевой буфер размера size. До начала обработки пакеты хранятся в буфере.
Если буфер полностью заполнен в момент поступления пакета (есть size пакетов, поступивших ранее, которые до сих пор не обработаны), этот
пакет отбрасывается и уже не будет обработан. Если несколько пакетов поступает в одно и то же время, они все будут сперва сохранены в буфер (несколько последних из них могут быть отброшены, если буфер заполнится).
Компьютер обрабатывает пакеты в порядке их поступления. Он начинает обрабатывать следующий пакет из буфера сразу после того,как обработает текущий пакет. Компьютер может простаивать, если все пакеты уже обработаны и в буфере нет пакетов. Пакет освобождает место в буфере сразу же, как компьютер заканчивает его обработку.
Формат входа.
Первая строка входа содержит размер буфера size и число пакетов n. Каждая из следующих n строк содержит два числа: время arrivali прибытия i-го пакета и время durationi,
необходимое на его обработку. Гарантируется, что arrival1 ≤ arrival2 ≤ · · · ≤ arrivaln. При этом может оказаться, что arrivali−1 = arrivali. В таком случае считаем, что пакет i − 1 поступил раньше пакета i.
Формат выхода.
Для каждого из n пакетов выведите время, когда процессор начал его обрабатывать, или −1, если пакет был отброшен.
Ограничения.
Все числа во входе целые. 1 ≤ size ≤ 10^5;
0 ≤ n ≤ 10^5;
0 ≤ arrivali ≤ 10^6;
0 ≤ durationi ≤ 10^3;
arrivali ≤ arrivali+1 для всех 1 ≤ i ≤ n − 1.