import pandas as pd
import random
import os
current_dir = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(current_dir, '대전광역시 서구_갈마도서관 도서현황_20240903.csv')  
df = pd.read_csv(input_file)
df['가격'] = [random.randint(1000, 10000) for _ in range(len(df))]
output_file = os.path.join(current_dir, 'books.csv')
df.to_csv(output_file, index=False)
