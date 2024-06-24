import json
var = {
      "Subjects": {
                  "Maths":85,
                  "Physics":90
                   }
      }
with open("annotations.jsonl",'w') as f:
    json.dump(var,f)