type state = {scoreA: int};
let initialState: state = {scoreA: 0};
let reducer = (_state, _action) => {
  {scoreA: 1};
};

[@react.component]
let make = () => {
  <div>
     <div className="test" /> <AnotherComponent state=1 /> </div>;
    //let (state, dispatch) = React.useReducer(reducer, initialState);
};
