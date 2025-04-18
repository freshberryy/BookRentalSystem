import pandas as pd
import os
current_dir = os.path.dirname(os.path.abspath(__file__))
input_path = os.path.join(current_dir, 'books.csv') 
df = pd.read_csv(input_path, encoding='utf-8-sig')
df_10k = df.head(10000)
df_duplicated = pd.concat([df_10k, df_10k], ignore_index=True)
output_path = os.path.join(current_dir, 'books.csv')
df_duplicated.to_csv(output_path, index=False)
