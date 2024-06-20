# Full name: Duyen Nguyen


areas_dict = {}


# A class for object name and object description:
class AreaObject:
    def __init__(self, object_name: str, object_description: str) -> None:
        self.object_name = object_name
        self.object_description = object_description

# A class for Area information (area's name, area description, exit directions, and object (if any) in that area)
class Area:
    def __init__(self, area_name: str, description: str, exits: list, object: AreaObject) -> None:
        self.area_name = area_name
        self.description = description
        self.exits = exits
        self.object = object
        self.isVisited = False
        self.isExamined = False

# Create a graph that store Areas information (name, exit directions, neighbours name, area's object, etc)        
def createGraph() -> None:
    file = open("comp1405_f23_101314143_assignment_10_data.txt", "r")
    for line in file:
        if line.startswith("#") or len(line) == 0 or line == "\n":
            continue
        data = line.split(":")
        exitsList = []
        for i in range(2,8):
            if data[i] == "None":
                continue
            direction = findDirection(i)
            exitsList.append((direction, data[i]))
        if data[8] != "None":
            area_Object = AreaObject(data[8], data[9])
            area = Area(data[0], data[1], exitsList, area_Object)
        else:
            area = Area(data[0], data[1], exitsList, None)
        areas_dict[data[0].upper()] = area 

# A function that can store area directions as letter N, S, W, etc. 
def findDirection(index: int) -> str:
    if index == 2:
        return "N"
    if index == 3:
        return "S"
    if index == 4:
        return "W"
    if index == 5:
        return "E"
    if index == 6:
        return "U"
    if index == 7:
        return "D"

# A function that can track if the player has visited the area and examine an object     
def updateArea(area: Area, isVisited: bool, isExamined: bool) -> None:
    area.isVisited = isVisited
    area.isExamined = isExamined

# A function that print notifications for the player when there is no object in a particular area or if they have found one
def printObject_ifAny(area: Area) -> None:
    if area.object is None:
        print("No object is in this location.")
    else:
        print(f"You have found {area.object.object_name}. ({area.object.object_description})")
        area.isExamined = True
    areas_dict[area.area_name.upper()] = area

# A function that can move they player in the direction they want
def moveTo(area: Area, direction: str) -> Area:
    for i in range(len(area.exits)):
        exit = area.exits[i]
        if exit[0] == direction:
            area.isVisited = True
            areas_dict[area.area_name.upper()] = area
            return areas_dict[exit[1].upper()]
    return None

# A function that check whether the player is win the game or not
def checkGameFinished() -> bool:
    for area_name in areas_dict:
        area = areas_dict[area_name.upper()]
        if area.object is not None and (area.isVisited == False or area.isExamined == False) and area_name.upper() != "Entrance door".upper():
            return False
    return True

# A function that can show the area descriptions
def printAreaDescription_ifAny(area: Area) -> None:
    if area.description == "None":
        print("There is nothing.")
    else:
        print(f"{area.description}")

# A function that track how many areas they have explored and how many objects they have examined
def currentProgress() -> None:
    count_visitedArea = 0
    count_objectsExamined = 0
    for area_name in areas_dict:
        area = areas_dict[area_name.upper()]
        if area.isVisited == True:
            count_visitedArea += 1
        if area.isExamined == True:
            count_objectsExamined += 1
    print(f"Total areas visited: {count_visitedArea}. Total objects examined: {count_objectsExamined}")


# Main function of the game
def main():
    createGraph()
    currentArea = areas_dict["Entrance door".upper()]
    updateArea(currentArea, True, False)
    areas_dict[currentArea.area_name.upper()] = currentArea
    while True:
        print(f"Current location: {currentArea.area_name}")
        if checkGameFinished() == True:
            print("Yay, you have completed the game. Congratulation winner!")
            break
        currentProgress()
        command = input("Type 'look' to explore this location or 'examine' to find the object. To move to different areas, enter 'N' (North), 'S' (South), 'W' (West), 'E' (East), 'U' (Upstairs), 'D' (Downstairs): ").upper()
        if command == "LOOK":
            printAreaDescription_ifAny(currentArea)
        elif command == "EXAMINE":
            printObject_ifAny(currentArea)
        elif command in ["N", "S", "W", "E", "U", "D"]:
            newArea = moveTo(currentArea, command)
            if newArea is not None:
                currentArea = newArea
            else:
                print("You cannot move in this direction, please choose another direction.")
        else:
            print("Invalid command")

    
main()
