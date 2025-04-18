import pandas as pd
import os
import re
current_dir = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(current_dir, 'b.csv')  # 실제 파일명으로 바꿔주세요
output_file = os.path.join(current_dir, 'books.csv')
df = pd.read_csv(input_file, encoding='cp949')
def clean_year(value):
    if pd.isna(value):
        return 0
    digits = re.sub(r'[^0-9]', '', str(value))
    return int(digits) if digits else 0

df['출판년'] = df['출판년'].apply(clean_year)
df.to_csv(output_file, index=False, encoding='cp949')
