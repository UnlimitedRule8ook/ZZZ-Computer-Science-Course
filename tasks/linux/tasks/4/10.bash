# Выведи мне топ 5 файлов, в которых чаще всего встречается слово pizza

find . -type f | grep -v "pizza" | sort -r | head -5
