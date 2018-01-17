let component = ReasonReact.statelessComponent("String");

let make = (~text, _children) => {
    ...component,
    render: (_) => ReasonReact.stringToElement(text)
};