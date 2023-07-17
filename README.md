## Тестовое задание по реализации приложения с простыми алгоритмами обработки изображений
### Сборка на ОС Linux (Протестировано на дистрибутиве Ubuntu 22.04 lts):
1. Необходимо установить библиотеку Eigen для работы с матрицами.

```bash
sudo apt install -y libeigen3-dev
```
2. Также устанавливаем Qt и зависимости: https://wiki.qt.io/Building_Qt_Creator_from_Git_on_Ubuntu_22.04

3. Склонировать данный репозиторий и перейти в его корень:
```bash
git clone https://github.com/LeekaiDel/TestTask.git
cd ~/TestTask 
```
4. Создать директорию build и сконфигурировать cmake:
```bash
mkdir build && cd build/
cmake ../ImageViewerQt/
```
5. Выполнить сборку проектра:
```bash
make -j4
```
6. Запустить приложение:
```bash
./ImageViewerQt
```
### Сборка на ОС Windows 10:
