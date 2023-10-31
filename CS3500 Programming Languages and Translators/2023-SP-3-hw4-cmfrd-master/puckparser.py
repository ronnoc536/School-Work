import re

def error(msg):
  print("INVALID!")
  print("Error: " + msg + ", got \"" +CODE[INDEX][1] +"\"")
  exit()

def setToken(cd):
  global TOKEN
  global INDEX
  global CODE
    
  TOKEN = cd[0][0]
  CODE = cd
  INDEX = 0


def getToken():
  global TOKEN
  global INDEX
  global CODE
    
  INDEX += 1
  if(INDEX <= len(CODE)-1):
    TOKEN = CODE[INDEX][0]

def toTokens(lst):
  st = []
  for l in lst:
    if (re.search("[+-]*[0-9]+",l)):
      st.append(['int',l])
    elif (re.search("[+-]*[0-9]+[.][0-9]+",l)):
      st.append(['dec',l])
    elif (re.search("[\"][^\"\"]+[\"]",l)):
      st.append(['str',l])
    elif (re.search(";",l)):
      st.append(['col',l])
    elif (l == '.'):
      st.append(['per',l])
    elif (l == '['):
      st.append(['lbr',l])
    elif (l == ']'):
      st.append(['rbr',l])
    elif (l == '('):
      st.append(['lpr',l])
    elif (l == ')'):
      st.append(['rpr',l])
    elif (l == 'PRINT'):
      st.append(['pri',l])
    elif (l == ':='):
      st.append(['asn',l])
    elif (l == '~'):
      st.append(['neg',l])
    elif (re.search("[<>=#]",l)):
      st.append(['rel',l])
    elif (re.search("[+-]|OR|&",l)):
      st.append(['add',l])
    elif (re.search("[*/]|AND",l)):
      st.append(['mul',l])
    elif (re.search("[a-zA-Z][a-zA-z0-9_]*",l)):
      st.append(['ide',l])
    else:
      print("Unexpected error caused by token",l)
  return st

def is_MulOperator():
    if(TOKEN == "mul"):
        getToken()
    else:
        error("MulOperator expected")
        
def is_AddOperator():
  if(TOKEN == "add"):
    getToken()
  else:
    error("AddOperator expected")
        
def is_Factor():
  if TOKEN in ['int','dec','str','ide']:
    getToken()
  elif (TOKEN == "lpr"):
    getToken()
    is_Expression()
    if(TOKEN=="rpr"):
      getToken()
    else:
      error("\")\" expected")
  elif (TOKEN == "neg"):
    getToken()
    is_Factor()
  else:
    error("Factor expected")

def is_Term():
  is_Factor()
  while(TOKEN == "mul"):
    is_MulOperator()
    is_Factor()

def is_SimpleExpression():
  is_Term()
  while(TOKEN == "add"):
    is_AddOperator()
    is_Term()

def is_Expression():
  is_SimpleExpression()
  if(TOKEN == "rel"):
    getToken()
    is_SimpleExpression()
        
def is_Selector():
  if(TOKEN == "per"):
    getToken()
    if(TOKEN == "ide"):
      getToken()
    else:
      error("Expected identifier")
  elif(TOKEN == 'lbr'):
    getToken()
    is_Expression()
    if(TOKEN == 'rbr'):
      getToken()
    else:
      error("Expected \"]\"")
        

def is_Designator():
  if(TOKEN == "ide"):
    getToken()
    while(TOKEN == "per" or TOKEN == "lbr"):
      is_Selector()
        

def is_Assignment():
  is_Designator()
  if(TOKEN == "asn"):
    getToken()
    is_Expression()
  else:
    error("\":=\" expected")

def is_PrintStatement():
  if(TOKEN == "pri"):
    getToken()
    if(TOKEN == "lpr"):
      getToken()
      is_Expression()
      if(TOKEN == "rpr"):
        getToken()
      else:
        error("Expected \")\"")
    else:
      error("Expected \"(\"")

def is_Statement():
  if (TOKEN == "ide"):
    is_Assignment()
  elif(TOKEN == "pri"):
    is_PrintStatement()
        
def is_StatementSequence():
  is_Statement()
  while(TOKEN == "col"):
    getToken()
    is_Statement()
    

if __name__ == '__main__':
  c = []
  INDEX = 0
  while(1):
    try:
      l=input().split()
    except:
      break
    for x in l:
      c.append(x)
  c = toTokens(c)
  setToken(c)
  is_StatementSequence()
  print("CORRECT")