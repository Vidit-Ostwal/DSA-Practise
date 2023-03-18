class BrowserHistory:
    Forward = []
    Backward = []

    def __init__(self, temp_string: str):
        # print(self.Backward)

        while len(self.Backward):
            self.Backward.pop()

        while len(self.Forward):
            self.Forward.pop()

        # print(temp_string)
        self.Backward.append(temp_string)
        # print(len(self.Backward))
        # print(self.Backward[0])

    def visit(self, url: str) -> None:
        self.Backward.append(url)

        while len(self.Forward):
            self.Forward.pop()

    def back(self, steps: int) -> str:
        while steps and len(self.Backward):
            steps = steps - 1
            self.Forward.append(self.Backward[len(self.Backward) - 1]) 
            self.Backward.pop()

        if len(self.Backward) == 0:
            self.Backward.append(self.Forward[len(self.Forward) - 1])
            self.Forward.pop()
        
        return self.Backward[len(self.Backward) - 1]

    def forward(self, steps: int) -> str:
        while steps and len(self.Forward):
            steps = steps - 1
            self.Backward.append(self.Forward[len(self.Forward) - 1])
            self.Forward.pop()
        
        return self.Backward[len(self.Backward) - 1]
        
        

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)