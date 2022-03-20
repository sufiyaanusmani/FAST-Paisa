import pandas as pd
from pandas_profiling import ProfileReport

df = pd.read_csv('a.csv')
print(df)

profile = ProfileReport(df)
profile.to_file(output_file="report.html")