import React, { useState } from "react";
import "./styles.css";

function Result({result}) {
  return <div className="result"><h1>{result}</h1></div>
}

function Button({ children, onClick}) {
  return <div onClick={onClick} key={Math.random()} className="btn">{children}</div>
}

function NumPad({updateExpression, evaluateExpression}) {
  let count = 10;
  let buttons = [];
  for(let i=0;i<count;i++) {
    buttons.push(<Button onClick={() => updateExpression(expression => expression + i)} key={Math.random()}>{i}</Button>)
  }

  return <div className="input-pad">
    {buttons}
    <Button onClick={() => evaluateExpression()}>=</Button>
    <Button onClick={() => { updateExpression(''); evaluateExpression(null); } }>AC</Button>
  </div>
}

function Operators({ updateExpression }) {
  return (
    <div className="operators">
      <Button onClick={() => updateExpression(expression => expression + '+')} >+</Button>
      <Button onClick={() => updateExpression(expression => expression + '-')} >-</Button>
      <Button onClick={() => updateExpression(expression => expression + '*')} >*</Button>
      <Button onClick={() => updateExpression(expression => expression + '/')} >/</Button>
    </div>
  )
}

function calc(expression, symbol) {
  let regex, result, operand1, operand2, matched;
  
  switch(symbol) {
    case '/':
        regex = /\d+\/\d+/;
        matched = expression.match(regex);

        console.log(matched);
        while(matched !== null) {
          [operand1, operand2] = matched[0].split(symbol);
          result = parseInt(operand1) / parseInt(operand2);
          expression = expression.replace(regex, result);

          console.log(expression);
          matched = expression.match(regex);
        }
        return expression;
    case '*':
        regex = /\d+\*\d+/;
        matched = expression.match(regex);
        while(matched !== null) {
          [operand1, operand2] = matched[0].split(symbol);
          result = parseInt(operand1) * parseInt(operand2);
          expression = expression.replace(regex, result);

          console.log(expression);
          matched = expression.match(regex);
        }
        return expression;
    case '+':
        regex = /\d+\+\d+/;
        matched = expression.match(regex);
        while(matched !== null) {
          [operand1, operand2] = matched[0].split(symbol);
          result = parseInt(operand1) + parseInt(operand2);
          expression = expression.replace(regex, result);

          console.log(expression);
          matched = expression.match(regex);
        }
        return expression;
    default:
        regex = /\d+\-\d+/;
        matched = expression.match(regex);
        while(matched !== null) {
          [operand1, operand2] = matched[0].split(symbol);
          result = parseInt(operand1) - parseInt(operand2);
          expression = expression.replace(regex, result);

          console.log(expression);
          matched = expression.match(regex);
        }
        return expression;
  }
}

export default function App() {
  const [expression, setExpression] = useState('');
  const [result, setResult] = useState(0);

  const evaluateExpression = (exp) => {
    if(exp === null) {
      return setResult(0);
    }
    let transform = calc(expression, '/');
    transform = calc(transform, '*');
    transform = calc(transform, '+');
    transform = calc(transform, '-');
    setResult(transform);
    setExpression(transform);
  }

  return (
    <div className="App">
      <div className="calc">
        <Result result={expression ? expression : result}/>
        <div className="actions">
          <NumPad evaluateExpression={(exp) => evaluateExpression(exp)} updateExpression={setExpression}/>
          <Operators updateExpression={setExpression}/>
        </div>
      </div>
    </div>
  );
}
