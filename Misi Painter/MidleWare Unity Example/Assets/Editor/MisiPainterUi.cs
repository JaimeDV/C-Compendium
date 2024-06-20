
using Codice.Client.BaseCommands;
using System.Collections.Generic;
using System.Drawing;
using UnityEditor;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using UnityEngine.UIElements;
using Button = UnityEngine.UIElements.Button;
using Color = UnityEngine.Color;
using Image = UnityEngine.UIElements.Image;

/// @copyright © 2024+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 04/05/2024
/// @brief Creates Misipainters Ui inside the unity inspector 



/// @brief Defines a custom editor window for the MisiPainter tool.
public class MisiPainterUi : EditorWindow
{

    /// @brief Creates and shows the MisiPainter editor window.
    [MenuItem("Utility/MisiPainter")]
    static void CreateUI()
    {
        MisiPainterWindow window = CreateInstance<MisiPainterWindow>();
        window.titleContent = new GUIContent("Misi Painter");
        // Show the window as a utility window
        window.ShowUtility();
    }
    
}

/// @brief creates a custom editor window for the MisiPainter tool.
public class MisiPainterWindow : EditorWindow
{
    UnityEngine.UIElements.Button button;
    VisualElement activeElement;
    public Sprite pSprite;
    int heigh;
    int width;
    string path;
    private void OnEnable()
    {
        titleContent = new GUIContent("Misi Painter");

        // Create a new root visual element
        VisualElement drawer = new VisualElement();
        drawer.style.flexDirection = FlexDirection.Row;
        drawer.style.justifyContent = Justify.FlexStart;
        drawer.style.alignItems = Align.Center;
      

        // Create button
        button = new Button();
        button.style.height = 15;
        button.style.flexDirection = FlexDirection.Column;
        button.style.justifyContent = Justify.Center;
        button.style.alignItems = Align.Center;
        button.text = "New file";
        button.clicked += StartSettings;
        drawer.Add(button);

        button = new Button();
        button.style.height = 15;
        button.style.flexDirection = FlexDirection.Column;
        button.style.justifyContent = Justify.Center;
        button.style.alignItems = Align.Center;
        button.text = "Load file";
        button.clicked += StartLoad;
        drawer.Add(button);


        // Add root visual element to the window
        drawer.style.width = 620; // Set width for better visibility
        drawer.style.height = 25; // Set height for better visibility
        drawer.style.backgroundColor = Color.white; // Set background color for better visibility
        drawer.style.borderBottomWidth = 1; // Add border for better visibility
        drawer.style.borderBottomColor = Color.black; // Add border color for better visibility
        drawer.style.borderBottomLeftRadius = 5; // Add border radius for better visibility
        drawer.style.borderBottomRightRadius = 5; // Add border radius for better visibility
        drawer.style.marginTop = 10; // Add margin for better visibility
        drawer.style.marginBottom = 5; // Add margin for better visibility
        drawer.style.marginLeft = 10; // Add margin for better visibility
        drawer.style.marginRight = 10; // Add margin for better visibility
        drawer.style.paddingTop = 10; // Add padding for better visibility
        drawer.style.paddingBottom = 10; // Add padding for better visibility
        drawer.style.paddingLeft = 10; // Add padding for better visibility
        drawer.style.paddingRight = 10; // Add padding for better visibility
        drawer.style.borderTopWidth = 1; // Add border for better visibility
        drawer.style.borderTopColor = Color.black; // Add border color for better visibility
        drawer.style.borderTopLeftRadius = 5; // Add border radius for better visibility
        drawer.style.borderTopRightRadius = 5; // Add border radius for better visibility

        this.rootVisualElement.Add(drawer); // Add root visual element to the wind

        // Set minimum and maximum size of the window
        minSize = new Vector2(640, 360);
        maxSize = new Vector2(640, 360);
    }

    /// @brief Creates and replaces the main window to the painter window
    /// @param given_width Width of the canvas. Hardcoded at the moment
    /// @param given_heigh Height of the canvas. Hardcoded at the moment
    /// @param loads Specifies whether to load an existing file.
    private void CreatePainterWindow(int given_width, int given_heigh, bool loads)
    {

        MisiPainterPaintWindow window = CreateInstance<MisiPainterPaintWindow>();
        window.titleContent = new GUIContent("Misi Painter");


        window.heigh= given_heigh;
        window.width= given_width;
        window.minSize = new Vector2(640, 540);
        window.maxSize = new Vector2(640, 540);
        window.path = path;
        window.loads= loads;    
        // Show the window as a utility window
        window.ShowUtility();  
        window.CreateWindow();
        
        this.Close();
    }

    /// @brief Sets the window for canvas creation.
    private void StartSettings()
    {
        // Remove the previous activeElement from the hierarchy if it exists
        if (activeElement != null && activeElement.parent != null)
        {
            activeElement.RemoveFromHierarchy();
        }

        // Create a new activeElement
        activeElement = new VisualElement();
        VisualElement drawer = new VisualElement();
        drawer.style.flexDirection = FlexDirection.Column;
        drawer.style.justifyContent = Justify.FlexStart;
        drawer.style.alignItems = Align.Center;

        // Add root visual element to the window
        drawer.style.width = 620; // Set width for better visibility
        drawer.style.height = 350; // Set height for better visibility
        drawer.style.backgroundColor = Color.white; // Set background color for better visibility
        drawer.style.borderBottomWidth = 1; // Add border for better visibility
        drawer.style.borderBottomColor = Color.black; // Add border color for better visibility
        drawer.style.borderBottomLeftRadius = 5; // Add border radius for better visibility
        drawer.style.borderBottomRightRadius = 5; // Add border radius for better visibility
        drawer.style.marginTop = 0; // Add margin for better visibility
        drawer.style.marginBottom = 10; // Add margin for better visibility
        drawer.style.marginLeft = 10; // Add margin for better visibility
        drawer.style.marginRight = 10; // Add margin for better visibility
        drawer.style.paddingTop = 10; // Add padding for better visibility
        drawer.style.paddingBottom = 10; // Add padding for better visibility
        drawer.style.paddingLeft = 10; // Add padding for better visibility
        drawer.style.paddingRight = 10; // Add padding for better visibility
        drawer.style.borderTopWidth = 1; // Add border for better visibility
        drawer.style.borderTopColor = Color.black; // Add border color for better visibility
        drawer.style.borderTopLeftRadius = 5; // Add border radius for better visibility
        drawer.style.borderTopRightRadius = 5; // Add border radius for better visibility


        Label width = new Label();
        width.text = "Width";
        width.style.color = Color.black; // Set label color to black
        width.style.unityTextAlign = TextAnchor.MiddleCenter; // Set label text alignment to center
        width.style.width = 100; // Set label width


        TextField textFieldW = new TextField();
        textFieldW.SetValueWithoutNotify("32"); // Set initial value
        textFieldW.style.width = 100; // Set width of the text field
        textFieldW.maxLength = 4;


        Label heigh = new Label();
        heigh.text = "Heigh";
        heigh.style.color = Color.black; // Set label color to black
        heigh.style.unityTextAlign = TextAnchor.MiddleCenter; // Set label text alignment to center
        heigh.style.width = 100; // Set label width


        TextField textFieldH = new TextField();
        textFieldH.SetValueWithoutNotify("32"); // Set initial value
        textFieldH.style.width = 100; // Set width of the text field
        textFieldH.maxLength = 4;

        // Create button
        button = new UnityEngine.UIElements.Button();
        button.style.height = 15;
        button.style.flexDirection = FlexDirection.Column;
        button.style.justifyContent = Justify.Center;
        button.style.alignItems = Align.Center;
        button.text = "Create file";
        button.clicked += () => CreatePainterWindow(int.Parse(textFieldH.value), int.Parse(textFieldW.value), false);

        drawer.Add(width);
        drawer.Add(textFieldH);
        drawer.Add(heigh);
        drawer.Add(textFieldW);


        Label pathLabel = new Label();
        pathLabel.text = "Safe/image Path";
        pathLabel.style.color = Color.black; // Set label color to black
        pathLabel.style.unityTextAlign = TextAnchor.MiddleCenter; // Set label text alignment to center
        pathLabel.style.width = 100; // Set label width

        TextField pathField = new TextField();
        pathField.SetValueWithoutNotify("D:/Test.png"); // Set initial value
        path = "D:/Test.png";
        pathField.RegisterValueChangedCallback(evt => path = evt.newValue);  // Log new value when changed
        pathField.style.width = 500; // Set width of the text field

      

        drawer.Add(pathLabel);
        drawer.Add(pathField);
        drawer.Add(button);

        // Add the drawer to the activeElement
        activeElement.Add(drawer);

        // Add the activeElement to the root visual element of the window
        this.rootVisualElement.Add(activeElement);
    }

    /// @brief Sets the window for canvas load. Acts as StartSetting at the moment 
    private void StartLoad()
    {
        // Remove the previous activeElement from the hierarchy if it exists
        if (activeElement != null && activeElement.parent != null)
        {
            activeElement.RemoveFromHierarchy();
        }

        // Create a new activeElement
        activeElement = new VisualElement();
        VisualElement drawer = new VisualElement();
        drawer.style.flexDirection = FlexDirection.Column;
        drawer.style.justifyContent = Justify.FlexStart;
        drawer.style.alignItems = Align.Center;

        // Add root visual element to the window
        drawer.style.width = 620; // Set width for better visibility
        drawer.style.height = 350; // Set height for better visibility
        drawer.style.backgroundColor = Color.white; // Set background color for better visibility
        drawer.style.borderBottomWidth = 1; // Add border for better visibility
        drawer.style.borderBottomColor = Color.black; // Add border color for better visibility
        drawer.style.borderBottomLeftRadius = 5; // Add border radius for better visibility
        drawer.style.borderBottomRightRadius = 5; // Add border radius for better visibility
        drawer.style.marginTop = 0; // Add margin for better visibility
        drawer.style.marginBottom = 10; // Add margin for better visibility
        drawer.style.marginLeft = 10; // Add margin for better visibility
        drawer.style.marginRight = 10; // Add margin for better visibility
        drawer.style.paddingTop = 10; // Add padding for better visibility
        drawer.style.paddingBottom = 10; // Add padding for better visibility
        drawer.style.paddingLeft = 10; // Add padding for better visibility
        drawer.style.paddingRight = 10; // Add padding for better visibility
        drawer.style.borderTopWidth = 1; // Add border for better visibility
        drawer.style.borderTopColor = Color.black; // Add border color for better visibility
        drawer.style.borderTopLeftRadius = 5; // Add border radius for better visibility
        drawer.style.borderTopRightRadius = 5; // Add border radius for better visibility

        Label pathLabel = new Label();
        pathLabel.text = "Safe/image Path";
        pathLabel.style.color = Color.black; // Set label color to black
        pathLabel.style.unityTextAlign = TextAnchor.MiddleCenter; // Set label text alignment to center
        pathLabel.style.width = 100; // Set label width

        TextField Path = new TextField();
        Path.SetValueWithoutNotify("D:/Test.png"); // Set initial value
        path = "D:/Test.png";
        Path.RegisterValueChangedCallback(evt => Debug.Log(evt.newValue)); // Log new value when changed
        Path.style.width = 500; // Set width of the text field

        // Create button
        button = new Button();
        button.style.height = 15;
        button.style.flexDirection = FlexDirection.Column;
        button.style.justifyContent = Justify.Center;
        button.style.alignItems = Align.Center;
        button.text = "Load file";
        button.clicked += () => CreatePainterWindow(0, 0, true);

        drawer.Add(pathLabel);
        drawer.Add(Path);
        drawer.Add(button);

        // Add the drawer to the activeElement
        activeElement.Add(drawer);

        // Add the activeElement to the root visual element of the window
        this.rootVisualElement.Add(activeElement);
    }

}


/// @brief class container that holds the Ui elements that acts as pixel for the ui.
public class GridItem
{
    VisualElement button;
    int x;
    int y;
    float pixelSize;
    MisiPainterAuxClass gridStatus;
    static bool paiting=false;
    static Color CurrentColor;
    static List<GridItem> gridItems = new List<GridItem>();

    /// @brief default Griditem Constructor
    /// @param newButton The UI element representing the button.
    /// @param Nx The X coordinate of the grid item.
    /// @param Ny The Y coordinate of the grid item.
    /// @param NpixelSize The size of the grid item pixel.
    public GridItem(VisualElement newButton, int Nx, int Ny, float NpixelSize)
    {
        button = newButton;
        x= Nx;
        y= Ny;
        pixelSize = NpixelSize;
        CreateObject();
    }

    /// @brief generic contructor used only as a bridge to  change the color of all grid item. Unused
    public GridItem()
    {
       
    }

    /// @brief Changes the current painting color.
    /// @param newColor The new color to be set as the current color.
    public void ChangeColor(Color newColor)
    {
        CurrentColor= newColor;
    }

    /// @brief Assigns a reference to the canvas to the grid item.
    /// @param grid The grid status object to be assigned.
    public void AssignCanvas(MisiPainterAuxClass grid)
    {
        gridStatus = grid;
    }

    /// @brief Cleans the entire grid by setting all grid items to white.
    public static void CleanGrid()
    {
        foreach (var item in gridItems)
        {
            item.SetPixelColor(255, 255, 255, 255);
        }
    }

    /// @brief Initializes the grid item Visually & in the back end
    void CreateObject()
    {
        CurrentColor = new Color(255, 255, 255, 255);
        button.style.width = pixelSize;
        button.style.height = pixelSize;

        button.style.marginLeft = 1f; // Set margin
        button.style.marginRight = 1f; // Set margin
        button.style.marginTop = 1f; // Set margin
        button.style.marginBottom = 1f; // Set margin


        button.style.backgroundColor = new StyleColor(Color.black); // Set a background color for visibility

        button.RegisterCallback<MouseDownEvent>(evt =>
        {
            if (evt.button == 1) // Right mouse button
            {
                paiting = true;
                CurrentColor= new Color(255, 255, 255, 255);
                CleanPixel();
                evt.StopPropagation();
            } 
            else
            {
                paiting = true;
                SetPixelColor((int)CurrentColor.r, (int)CurrentColor.g, (int)CurrentColor.b, (int)CurrentColor.a);
                evt.StopPropagation();
            }
        });

        button.RegisterCallback<MouseUpEvent>(evt =>
        {
            paiting = false;
            evt.StopPropagation();
        });

       

        button.RegisterCallback<MouseMoveEvent>(evt =>
        {
            if (paiting)
            {
                SetPixelColor((int)CurrentColor.r, (int)CurrentColor.g, (int)CurrentColor.b, (int)CurrentColor.a);
                evt.StopPropagation();
            }
        });
        gridItems.Add(this);
    }


    /// @brief Gets the button VisualElement element of the grid item.
    /// @return The button VisualElement element.
    public VisualElement GetButton()
    {
        return button;
    }

    /// @brief Debug only. Prints the pixel coordinates 
    public void GetPixel()
    {
        Debug.Log("I am " + x + "  " + y); 
    }

    /// @brief Sets the color of the grid item pixel vissualy & in the backend.
    /// @param r Red component of the color.
    /// @param g Green component of the color.
    /// @param b Blue component of the color.
    /// @param a Alpha component of the color.
    public void SetPixelColor(int r, int g, int b, int a)
    {
        Color colornew = new Color(r,g,b,a);
        button.style.backgroundColor = colornew;
        gridStatus.SetPixelColor(x,y, r,g,b,a);

    }

    /// @brief Cleans the grid item pixel by setting it to white.
    public void CleanPixel()
    {
        Color colornew = new Color(255, 255, 255, 255);
        button.style.backgroundColor = colornew;
        gridStatus.CleanPixel(x,y);
    }

}


//The grid window
public class MisiPainterPaintWindow : EditorWindow
{

    MisiPainterAuxClass auxClass;
    public int heigh;
    public int width;
    public string path;
    public bool loads;

    public MisiPainterPaintWindow(int heigh, int width)
    {
        this.heigh = heigh;
        this.width = width;
    }

    /// @brief Creates an instance to the main tool drawing window.
    public void CreateWindow()
    {
         auxClass = new MisiPainterAuxClass(heigh, width, path);
         titleContent = new GUIContent("Misi Painter");

        //for this alfa the grid size is hardcoded 

        int numColumns = 32; // Number of columns in the grid
        int numRows = 32; // Number of rows in the grid

        // Define the fixed size of the window
        int windowWidth = 640;
        int windowHeight = 540;

        // Define the width of the toolDrawer
        int toolDrawerWidth = 100;

        // Calculate the available width for the drawer
        int availableWidth = windowWidth - toolDrawerWidth;

        // Calculate the size of each pixel
        float pixelWidth = (float)availableWidth / numColumns;
        float pixelHeight = (float)windowHeight / numRows;
        float pixelSize = 14.55f;

        // Create the main container to hold both drawer and toolDrawer
        VisualElement mainContainer = new VisualElement();
        mainContainer.style.flexDirection = FlexDirection.Row; // Set flex direction to Row for horizontal layout

        // Create drawer container to hold the drawer content
        VisualElement drawerContainer = new VisualElement();
        drawerContainer.style.width = availableWidth;
        drawerContainer.style.height = windowHeight;
        drawerContainer.style.overflow = Overflow.Hidden; // Clip overflow content

        // Create drawer element
        VisualElement drawer = new VisualElement();
        drawer.style.flexDirection = FlexDirection.Row; // Change to Row for grid layout
        drawer.style.flexWrap = Wrap.Wrap; // Allow items to wrap to new rows
        drawer.style.alignItems = Align.Center;
        drawer.style.overflow = Overflow.Hidden;

        // Set styles for drawer
        drawer.style.width = Length.Percent(100); // Set width to 100% to fill container
        drawer.style.height = Length.Percent(100); // Set height to 100% to fill container
        drawer.style.backgroundColor = Color.gray; // Set background color for better visibility
        drawer.style.marginTop = 10; // Add margin for better visibility
        drawer.style.marginBottom = 10; // Add margin for better visibility
        drawer.style.marginLeft = 10; // Add margin for better visibility
        drawer.style.marginRight = 10; // Add margin for better visibility


        if(loads)
        {
            auxClass.LoadFile(path);
        }

        // Add grid-like elements to drawer
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numColumns; j++)
            {
                VisualElement gridItem = new VisualElement();

                //Label a = new Label();
                //a.text = i.ToString();
                //gridItem.Add(a);

                List<int> Color = auxClass.GetPixelColor(j, i);

                GridItem gridButton = new GridItem(gridItem, j, i, pixelSize);
                gridButton.AssignCanvas(auxClass);
                gridButton.SetPixelColor(Color[0], Color[1], Color[2], Color[3]);
                drawer.Add(gridButton.GetButton());
            }
        }

        // Add drawer to drawer container
        drawerContainer.Add(drawer);

        // Add drawer container to mainContainer
        mainContainer.Add(drawerContainer);

        //Create toolDrawer element
        VisualElement toolDrawer = new VisualElement();
        toolDrawer.style.flexDirection = FlexDirection.Row; // Change to Row for grid layout
        toolDrawer.style.flexWrap = Wrap.Wrap; // Allow items to wrap to new rows
        toolDrawer.style.alignItems = Align.FlexStart;

        // Set styles for toolDrawer
        toolDrawer.style.width = toolDrawerWidth;
        toolDrawer.style.height = windowHeight - 20; // Adjust height to fit within the window
        toolDrawer.style.backgroundColor = Color.white; // Set background color for better visibility
        toolDrawer.style.marginTop = 10; // Add margin for better visibility
        toolDrawer.style.marginBottom = 10; // Add margin for better visibility
        toolDrawer.style.marginLeft = 5; // Add margin for better visibility
        toolDrawer.style.marginRight = 10; // Add margin for better visibility
        toolDrawer.style.paddingTop = 10; // Add padding for better visibility
        toolDrawer.style.paddingBottom = 10; // Add padding for better visibility
        toolDrawer.style.paddingLeft = 10; // Add padding for better visibility
        toolDrawer.style.paddingRight = 10; // Add padding for better visibility

        GridItem auxItem = new GridItem();

        var RedBox = new VisualElement
        {
            style =
            {
                width = 30,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                backgroundColor= new Color(255, 0, 0, 255)

    }

        };


        RedBox.RegisterCallback<MouseDownEvent>(evt =>
        {
            Color newColor = new Color(255, 0, 0, 255);
            auxItem.ChangeColor(newColor);
        });

        
        var blueBox = new VisualElement
        {
            style =
            {
                width = 30,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                backgroundColor=Color.blue

            }

        };


        blueBox.RegisterCallback<MouseDownEvent>(evt =>
        {
            Color newColor=new Color(0,0, 255, 255);
            auxItem.ChangeColor(newColor);
        });

       

       
        var yellowBox = new VisualElement
        {
            style =
            {
                width = 30,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                backgroundColor= new Color(255, 255, 0, 255)

    }

        };


        yellowBox.RegisterCallback<MouseDownEvent>(evt =>
        {
            Color newColor = new Color(255, 255, 0, 255);
            auxItem.ChangeColor(newColor);
        });

     

      
        var greenBox = new VisualElement
        {
            style =
            {
                width = 30,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                backgroundColor=new Color(0, 255, 0, 255)

    }

        };


        greenBox.RegisterCallback<MouseDownEvent>(evt =>
        {
            Color newColor = new Color(0, 255, 0, 255);
            auxItem.ChangeColor(newColor);
        });

       

        var blackbox = new VisualElement
        {
            style =
            {
                width = 30,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                backgroundColor=new Color(0, 0, 0, 255)

    }

        };


        blackbox.RegisterCallback<MouseDownEvent>(evt =>
        {
            Color newColor = new Color(0, 0, 0, 255);
            auxItem.ChangeColor(newColor);
        });

     
        var purpleBox = new VisualElement
        {
            style =
            {
                width = 30,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                backgroundColor= new Color(255, 0, 255, 255)

            }

        };


        purpleBox.RegisterCallback<MouseDownEvent>(evt =>
        {
            Color newColor = new Color(255, 0, 255, 255);
            auxItem.ChangeColor(newColor);
        });

       

        toolDrawer.Add(RedBox);
        toolDrawer.Add(blueBox);
        toolDrawer.Add(greenBox);
        toolDrawer.Add(yellowBox);
        toolDrawer.Add(blackbox);
        toolDrawer.Add(purpleBox);


        //var safebutton = new Button
        //{
        //    style =
        //    {
        //        width = 50,
        //        height = 30,
        //        justifyContent = Justify.Center,
        //        alignItems = Align.Center,
        //        //backgroundImage=texture,
        //        backgroundColor=Color.red,
        //        color=Color.green,
        //    }

        //};

        //Label safe = new Label();
        //safe.text = "Safe";
        //safe.style.color = Color.black; // Set label color to black
        //safe.style.unityTextAlign = TextAnchor.UpperLeft; // Set label text alignment to center
        //safe.style.width = 100; // Set label width

        //toolDrawer.Add(safe);
        //toolDrawer.Add(safebutton);


     
        var exportButton = new Button
        {
            style =
            {
                width = 50,
                height = 30,
                justifyContent = Justify.Center,
                alignItems = Align.Center,
                //backgroundImage=texture,
                backgroundColor=Color.red,
                color=Color.green,
                
            }

        };

        exportButton.clicked += () => auxClass.GenerateImage(path);



        Label export = new Label();
        export.text = "export as png";
        export.style.color = Color.black; // Set label color to black
        export.style.unityTextAlign = TextAnchor.UpperLeft; // Set label text alignment to center
        export.style.width = 100; // Set label width

        toolDrawer.Add(export);
        toolDrawer.Add(exportButton);





        // Add toolDrawer to mainContainer
        mainContainer.Add(toolDrawer);



        // Add mainContainer to rootVisualElement
        this.rootVisualElement.Add(mainContainer);
    }
    




}