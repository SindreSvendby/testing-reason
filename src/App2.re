type state = {scoreA: int};
let initialState: state = {scoreA: 0};
let reducer = (_state, _action) => {
  {scoreA: 1};
};

[@react.component]
let make = () => {
  let (state, _dispatch) = React.useReducer(reducer, initialState);
  <div> <div className="test" /> <AnotherComponent state /> </div>;
};
