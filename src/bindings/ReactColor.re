[@bs.module "react-color"] [@react.component]
external make:
  (
    ~color: string=?, // of a hex color
    ~onChange: unit => string=?,
    ~children: 'b=?
  ) =>
  React.element =
  "TwitterPicker";

/*

 // For all Pickers:
 //     -Color:
 //         - string of a hex color
 //         - object of rgb { r: 51, g: 51, b: 51 }  Both rgb and hsl will also take a a: 1 value for alpha. You can also use transparent.
 //         - object of hsl { h: 0, s: 0, l: .10 } Both rgb and hsl will also take a a: 1 value for alpha. You can also use transparent.
 //     - onChange
 //     - onChangeComplete

 // Spesific Pickers:
 //     -AlphaPicker
 //         width - String, Pixel value for picker width. Default 316px
 //         height - String, Pixel value for picker height. Default 16px
 //         direction - String Enum, horizontal or vertical. Default horizontal
 //         renderers - Object, Use { canvas: Canvas } with node canvas to do SSR
 //         pointer - React Component, Custom pointer component

 //     - BlockPicker:
 //         width - String, Pixel value for picker width. Default 170px
 //         colors - Array of Strings, Color squares to display. Default ['#D9E3F0', '#F47373', '#697689', '#37D67A', '#2CCCE4', '#555555', '#dce775', '#ff8a65', '#ba68c8']
 //         triangle - String, Either hide or top. Default top
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 //     -ChromePicker
 //         -disableAlpha - Bool, Remove alpha slider and options from picker. Default false
 //         -renderers - Object, Use { canvas: Canvas } with node canvas to do SSR

 //     -CirclePicker
 //         width - String, Pixel value for picker width. Default 252px
 //         colors - Array of Strings, Color squares to display. Default ["#f44336", "#e91e63", "#9c27b0", "#673ab7", "#3f51b5", "#2196f3", "#03a9f4", "#00bcd4", "#009688", "#4caf50", "#8bc34a", "#cddc39", "#ffeb3b", "#ffc107", "#ff9800", "#ff5722", "#795548", "#607d8b"]
 //         circleSize - Number, Value for circle size. Default 28
 //         circleSpacing - Number, Value for spacing between circles. Default 14
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 //     -CompactPicker
 //         colors - Array of Strings, Color squares to display. Default ['#4D4D4D', '#999999', '#FFFFFF', '#F44E3B', '#FE9200', '#FCDC00', '#DBDF00', '#A4DD00', '#68CCCA', '#73D8FF', '#AEA1FF', '#FDA1FF', '#333333', '#808080', '#cccccc', '#D33115', '#E27300', '#FCC400', '#B0BC00', '#68BC00', '#16A5A5', '#009CE0', '#7B64FF', '#FA28FF', '#000000', '#666666', '#B3B3B3', '#9F0500', '#C45100', '#FB9E00', '#808900', '#194D33', '#0C797D', '#0062B1', '#653294', '#AB149E']
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 //     -GithubPicker
 //         width - String, Pixel value for picker width. Default 200px
 //         colors - Array of Strings, Color squares to display. Default ['#B80000', '#DB3E00', '#FCCB00', '#008B02', '#006B76', '#1273DE', '#004DCF', '#5300EB', '#EB9694', '#FAD0C3', '#FEF3BD', '#C1E1C5', '#BEDADC', '#C4DEF6', '#BED3F3', '#D4C4FB']
 //         triangle - String, Either hide, top-left or top-right. Default top-left
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 //     -HuePicker
 //         width - String, Pixel value for picker width. Default 316px
 //         height - String, Pixel value for picker height. Default 16px
 //         direction - String Enum, horizontal or vertical. Default horizontal
 //         pointer - React Component, Custom pointer component

 //     -MaterialPicker
 //         (ikke noe spesielt)

 //     -PhotoshopPicker
 //         header - String, Title text. Default Color Picker
 //         onAccept - Function, Callback for when accept is clicked.
 //         onCancel - Function, Callback for when cancel is clicked.

 //     -SketchPicker
 //         disableAlpha - Bool, Remove alpha slider and options from picker. Default false
 //         presetColors - Array of Strings or Objects, Hex strings for default colors at bottom of picker. Default ['#D0021B', '#F5A623', '#F8E71C', '#8B572A', '#7ED321', '#417505', '#BD10E0', '#9013FE', '#4A90E2', '#50E3C2', '#B8E986', '#000000', '#4A4A4A', '#9B9B9B', '#FFFFFF']
 //         presetColors may also be described as an array of objects with color and title properties: [{ color: '#f00', title: 'red' }] or a combination of both

 //         width - Number, Width of picker. Default 200
 //         renderers - Object, Use { canvas: Canvas } with node canvas to do SSR
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 //     -SliderPicker
 //         pointer - React Component, Custom pointer component

 //     -SwatchesPicker
 //         width - Number, Pixel value for picker width. Default 320
 //         height - Number, Pixel value for picker height. Default 240
 //         colors - Array of Arrays of Strings, An array of color groups, each with an array of colors
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 //     -TwitterPicker
 //         width - String, Pixel value for picker width. Default 276px
 //         colors - Array of Strings, Color squares to display. Default ['#FF6900', '#FCB900', '#7BDCB5', '#00D084', '#8ED1FC', '#0693E3', '#ABB8C3', '#EB144C', '#F78DA7', '#9900EF']
 //         triangle - String, Either hide, top-left or top-right. Default top-left
 //         onSwatchHover - An event handler for onMouseOver on the <Swatch>s within this component. Gives the args (color, event)

 // Helper Components

 //     <Alpha />
 //         ...this.props - Pass down all the color props from your top-most component.
 //         pointer - Define a custom pointer component for the slider pointer.
 //         onChange - Function callback. Make sure this calls the onChange function of the parent to make it change.

 //     <EditableInput />
 //         label - Used to put a label on the input.
 //         value - The value to be passed down to the input.
 //         onChange - Function callback. Use this to call the onChange function of the parent. Returns an object where the key is the label and the value is the new value.
 //         style - Inline css to style the children elements: { wrap: {}, input: {}, label: {} }

 //     <Hue />
 //         ...this.props - Pass down all the color props from your top-most component.
 //         pointer - Define a custom pointer component for the slider pointer.
 //         onChange - Function callback. Make sure this calls the onChange function of the parent to make it change.
 //         direction - Display direction of the slider. Horizontal by default.

 //     <Saturation />
 //         ...this.props - Pass down all the color props from your top-most component.
 //         pointer - Define a custom pointer component for the slider pointer.
 //         onChange - Function callback. Make sure this calls the onChange function of the parent to make it change.

 //     <Checkboard />
 //         size - Number, Size of squares. Default 8
 */