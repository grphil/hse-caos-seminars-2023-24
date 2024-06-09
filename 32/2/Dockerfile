FROM python:3.12-alpine

# рабочая папка в контейнере
WORKDIR /app

# копируем файлы из нашего компа в контейнер
COPY . /app

# исполнить команду на этапе создания образа
RUN pip3 install -r requirements.txt

ENTRYPOINT ["python3", "app.py"]