import requests,json

def topArticles(limit):
    pageNumber=1    
    url = f"https://jsonmock.hackerrank.com/api/articles?page={pageNumber}" 
    resp = requests.get(url)
    res = json.loads(resp.content)
    total_pages = res["total_pages"]
    
    print(res)
    art = []
    for i in range(total_pages):
        pageNumber = i+1
        url = f"https://jsonmock.hackerrank.com/api/articles?page={pageNumber}" 
        resp = requests.get(url)
        res = json.loads(resp.content)
        cur = res["data"]
#         print("\n\n",cur)
        for x in cur:
#             print("\n\n *** \n",x["title"])
            if x["num_comments"] is None:
                continue
            if x["title"] is not None:
                art.append((x["num_comments"],x["title"]))
            elif x["story_title"] is not None:
                art.append((x["num_comments"],x["story_title"]))
    

    art.sort(reverse=True)
    ans=[]
#     ans = art[1][:limit]
    for i in range(limit):
        ans.append(art[i][1])
    return ans


ans = topArticles(2)
print(ans)
# -------------------------------------------------------------------------------------------------------------------------
import requests

url = "https://jsonmock.hackerrank.com/api/weather/search?name=all"

payload={}
headers = {}

response = requests.request("GET", url, headers=headers, data=payload)

print(response.text)
# -------------------------------------------------------------------------------------------------------------------------
