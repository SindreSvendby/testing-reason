
[@bs.module "react-swipeable-views"] [@react.component]
external make: 
(
    ~index: int=?,
    ~style: ReactDOMRe.Style.t=?,
    ~slideStyle: ReactDOMRe.Style.t=?,
    ~containerStyle: ReactDOMRe.Style.t=?,
    ~onChangeIndex: int => unit=?,
    ~children: 'b
) => 
React.element = "default";
