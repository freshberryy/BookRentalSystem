import pandas as pd
import random
import os
import re
from io import StringIO
current_dir = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(current_dir, '대전광역시 서구_갈마도서관 도서현황_20240903.csv')
with open(input_file, 'rb') as f:
    raw = f.read()
    decoded = raw.decode('cp949', errors='ignore')
df = pd.read_csv(StringIO(decoded))

#한자와 일본어 감지
def contains_cjk(text):
    return bool(re.search(r'[\u3400-\u4DBF\u4E00-\u9FFF\u3040-\u309F\u30A0-\u30FF]', text))
df = df[~df.apply(lambda row: contains_cjk(' '.join(map(str, row))), axis=1)]
df['대여료'] = [random.randint(1000, 10000) for _ in range(len(df))]
output_file = os.path.join(current_dir, 'books.csv')
df.to_csv(output_file, index=False)
